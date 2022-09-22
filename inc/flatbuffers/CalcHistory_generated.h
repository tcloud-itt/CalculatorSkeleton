// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CALCHISTORY_H_
#define FLATBUFFERS_GENERATED_CALCHISTORY_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 2 &&
              FLATBUFFERS_VERSION_MINOR == 0 &&
              FLATBUFFERS_VERSION_REVISION == 8,
             "Non-compatible flatbuffers version included");

struct CalcHistoryPairBuffer;
struct CalcHistoryPairBufferBuilder;

struct CalcHistoryBuffer;
struct CalcHistoryBufferBuilder;

struct CalcHistoryPairBuffer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CalcHistoryPairBufferBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_EQUATION = 4,
    VT_RESULT = 6
  };
  const flatbuffers::String *equation() const {
    return GetPointer<const flatbuffers::String *>(VT_EQUATION);
  }
  const flatbuffers::String *result() const {
    return GetPointer<const flatbuffers::String *>(VT_RESULT);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_EQUATION) &&
           verifier.VerifyString(equation()) &&
           VerifyOffset(verifier, VT_RESULT) &&
           verifier.VerifyString(result()) &&
           verifier.EndTable();
  }
};

struct CalcHistoryPairBufferBuilder {
  typedef CalcHistoryPairBuffer Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_equation(flatbuffers::Offset<flatbuffers::String> equation) {
    fbb_.AddOffset(CalcHistoryPairBuffer::VT_EQUATION, equation);
  }
  void add_result(flatbuffers::Offset<flatbuffers::String> result) {
    fbb_.AddOffset(CalcHistoryPairBuffer::VT_RESULT, result);
  }
  explicit CalcHistoryPairBufferBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<CalcHistoryPairBuffer> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CalcHistoryPairBuffer>(end);
    return o;
  }
};

inline flatbuffers::Offset<CalcHistoryPairBuffer> CreateCalcHistoryPairBuffer(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> equation = 0,
    flatbuffers::Offset<flatbuffers::String> result = 0) {
  CalcHistoryPairBufferBuilder builder_(_fbb);
  builder_.add_result(result);
  builder_.add_equation(equation);
  return builder_.Finish();
}

inline flatbuffers::Offset<CalcHistoryPairBuffer> CreateCalcHistoryPairBufferDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *equation = nullptr,
    const char *result = nullptr) {
  auto equation__ = equation ? _fbb.CreateString(equation) : 0;
  auto result__ = result ? _fbb.CreateString(result) : 0;
  return CreateCalcHistoryPairBuffer(
      _fbb,
      equation__,
      result__);
}

struct CalcHistoryBuffer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CalcHistoryBufferBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_HISTORY = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<CalcHistoryPairBuffer>> *history() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<CalcHistoryPairBuffer>> *>(VT_HISTORY);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_HISTORY) &&
           verifier.VerifyVector(history()) &&
           verifier.VerifyVectorOfTables(history()) &&
           verifier.EndTable();
  }
};

struct CalcHistoryBufferBuilder {
  typedef CalcHistoryBuffer Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_history(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CalcHistoryPairBuffer>>> history) {
    fbb_.AddOffset(CalcHistoryBuffer::VT_HISTORY, history);
  }
  explicit CalcHistoryBufferBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<CalcHistoryBuffer> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CalcHistoryBuffer>(end);
    return o;
  }
};

inline flatbuffers::Offset<CalcHistoryBuffer> CreateCalcHistoryBuffer(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CalcHistoryPairBuffer>>> history = 0) {
  CalcHistoryBufferBuilder builder_(_fbb);
  builder_.add_history(history);
  return builder_.Finish();
}

inline flatbuffers::Offset<CalcHistoryBuffer> CreateCalcHistoryBufferDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<CalcHistoryPairBuffer>> *history = nullptr) {
  auto history__ = history ? _fbb.CreateVector<flatbuffers::Offset<CalcHistoryPairBuffer>>(*history) : 0;
  return CreateCalcHistoryBuffer(
      _fbb,
      history__);
}

inline const CalcHistoryBuffer *GetCalcHistoryBuffer(const void *buf) {
  return flatbuffers::GetRoot<CalcHistoryBuffer>(buf);
}

inline const CalcHistoryBuffer *GetSizePrefixedCalcHistoryBuffer(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<CalcHistoryBuffer>(buf);
}

inline bool VerifyCalcHistoryBufferBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<CalcHistoryBuffer>(nullptr);
}

inline bool VerifySizePrefixedCalcHistoryBufferBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<CalcHistoryBuffer>(nullptr);
}

inline void FinishCalcHistoryBufferBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<CalcHistoryBuffer> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCalcHistoryBufferBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<CalcHistoryBuffer> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_CALCHISTORY_H_
