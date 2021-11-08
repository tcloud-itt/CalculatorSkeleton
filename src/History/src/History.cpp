////////////////////////////////////////////////////////////////////////////
/**
 *  @file   History.cpp
 *  @author Jeff Trent
 *  @date   Tue, June 22 2021
 *  @brief  Singleton containing calculator history
 */
////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <fstream>
#include <iostream>

#include "AddCalculator.h"
#include "DivideCalculator.h"
#include "History.h"
#include "MultiplyCalculator.h"
#include "Parser.h"
#include "SubtractCalculator.h"

namespace calculator {

std::shared_ptr<History> History::instance_ = nullptr;

// *****************************************************************************/
// ***************** History public methods ************************************/
// *****************************************************************************/

void History::appendCalculator(float answer, std::string originalEquation)
{
    flatbuffers::FlatBufferBuilder builder;

    auto equation = builder.CreateString(originalEquation);
    schema::CalculatorDataBuilder calculatorBuilder(builder);
    calculatorBuilder.add_answer(answer);
    calculatorBuilder.add_originalEquation(equation);
    auto calculatorOffset = calculatorBuilder.Finish();
    builder.Finish(calculatorOffset);

    // uint8_t *buf = builder.GetBufferPointer();
    // int size = builder.GetSize();
    // std::ofstream ouputFile("../data.bin", std::ios::binary);
    // ouputFile.write((char * )buf, size);
    // ouputFile.close();

    calculators_.push_back(schema::GetCalculatorData(builder.GetBufferPointer())->UnPack());
}

void History::clear()
{
    calculators_.clear();
}

schema::HistoryT *History::getBuiltHistory() //rename
{
    flatbuffers::FlatBufferBuilder builder(1024);
    schema::HistoryT *history = nullptr;

    std::vector<flatbuffers::Offset<schema::CalculatorData>> offsetCalculators;

    for(auto calculator : calculators_)
    {
        offsetCalculators.push_back(schema::CalculatorData::Pack(builder,calculator));
    }
    auto historyCalculators = builder.CreateVector(offsetCalculators);
    auto builtHistory = schema::CreateHistory(builder, historyCalculators);

    builder.Finish(builtHistory);
    uint8_t *buf = builder.GetBufferPointer();
    int size = builder.GetSize();

    std::ofstream ofile("../data.bin", std::ios::binary);
    ofile.write((char * )buf, size);
    ofile.close();

    history = schema::GetHistory(builder.GetBufferPointer())->UnPack();
        
    return history;
}

const schema::CalculatorDataT *History::getCalculatorData(int index)
{
    const schema::CalculatorDataT *calculator = nullptr;
    int size = calculators_.size();

    if (index >= 0 && index < size)
    {
        calculator = calculators_[index];
    }

    return calculator;
}

std::shared_ptr<History> History::getInstance()
{
    if (!instance_)
    {
        instance_ = std::shared_ptr<History>(new History());
    }
    return instance_;
}

int History::getSize()
{
    return calculators_.size();
}

void History::storedHistory()
{
    auto &history = History::getInstance()->getBuiltHistory()->list;
    if(history.empty())
    {
        std::string historyError = CalculatorStrings::NO_HISTORY;
        std::cout << Color::error(historyError) << std::endl;
    }
    else
    {
        int location = history.size() - 1;

        std::ofstream outputFile("../CalculatorData.bin");

        for(const auto e : calculators_) outputFile << e->originalEquation << " = " << e->answer<<"\n";

    }
}

void History::ReadFromFile()
{
    const std::string inputFile = "../data.bin";
    std::ifstream infile(inputFile, std::ios_base::binary | std::ios::in);
    infile.seekg(0, std::ios::end);
    int length = infile.tellg();
    infile.seekg(0, std::ios::beg);
    char* data = new char[length];
    infile.read(data, length);
    infile.close();

    calculators_.clear();

    auto historyData = schema::GetHistory(data)->UnPack();
    for(size_t i = 0; i < historyData->list.size(); i++)
    {
        // std::cout << "{" << i << "} " << historyData->list.at(i)->originalEquation << " = " << historyData->list.at(i)->answer << std::endl;
        calculators_.push_back(historyData->list.at(i).get());
    }

}

void History::printHistory()
{
    std::cout << "-----------------------History Start--------------------" << std::endl;
    
    for(int i = 0; i < calculators_.size(); i++)
    {
        std::cout << "{" << i << "} " << calculators_.at(i)->originalEquation << " = " << calculators_.at(i)->answer << std::endl;
    }
    std::cout << "-----------------------History End--------------------" << std::endl;
}

} // namespace calculator
