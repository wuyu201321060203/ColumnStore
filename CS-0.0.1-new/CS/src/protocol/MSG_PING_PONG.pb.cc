// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MSG_PING_PONG.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* PING_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PING_reflection_ = NULL;
const ::google::protobuf::Descriptor* PONG_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PONG_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MSG_5fPING_5fPONG_2eproto() {
  protobuf_AddDesc_MSG_5fPING_5fPONG_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MSG_PING_PONG.proto");
  GOOGLE_CHECK(file != NULL);
  PING_descriptor_ = file->message_type(0);
  static const int PING_offsets_[1] = {
  };
  PING_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PING_descriptor_,
      PING::default_instance_,
      PING_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PING, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PING, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PING));
  PONG_descriptor_ = file->message_type(1);
  static const int PONG_offsets_[1] = {
  };
  PONG_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PONG_descriptor_,
      PONG::default_instance_,
      PONG_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PONG, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PONG, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PONG));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MSG_5fPING_5fPONG_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PING_descriptor_, &PING::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PONG_descriptor_, &PONG::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MSG_5fPING_5fPONG_2eproto() {
  delete PING::default_instance_;
  delete PING_reflection_;
  delete PONG::default_instance_;
  delete PONG_reflection_;
}

void protobuf_AddDesc_MSG_5fPING_5fPONG_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023MSG_PING_PONG.proto\"\006\n\004PING\"\006\n\004PONG", 37);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MSG_PING_PONG.proto", &protobuf_RegisterTypes);
  PING::default_instance_ = new PING();
  PONG::default_instance_ = new PONG();
  PING::default_instance_->InitAsDefaultInstance();
  PONG::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MSG_5fPING_5fPONG_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MSG_5fPING_5fPONG_2eproto {
  StaticDescriptorInitializer_MSG_5fPING_5fPONG_2eproto() {
    protobuf_AddDesc_MSG_5fPING_5fPONG_2eproto();
  }
} static_descriptor_initializer_MSG_5fPING_5fPONG_2eproto_;


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

PING::PING()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PING::InitAsDefaultInstance() {
}

PING::PING(const PING& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PING::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PING::~PING() {
  SharedDtor();
}

void PING::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PING::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PING::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PING_descriptor_;
}

const PING& PING::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fPING_5fPONG_2eproto();  return *default_instance_;
}

PING* PING::default_instance_ = NULL;

PING* PING::New() const {
  return new PING;
}

void PING::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PING::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
  return true;
#undef DO_
}

void PING::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PING::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PING::ByteSize() const {
  int total_size = 0;
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PING::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PING* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PING*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PING::MergeFrom(const PING& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PING::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PING::CopyFrom(const PING& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PING::IsInitialized() const {
  
  return true;
}

void PING::Swap(PING* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PING::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PING_descriptor_;
  metadata.reflection = PING_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

PONG::PONG()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PONG::InitAsDefaultInstance() {
}

PONG::PONG(const PONG& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PONG::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PONG::~PONG() {
  SharedDtor();
}

void PONG::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PONG::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PONG::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PONG_descriptor_;
}

const PONG& PONG::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fPING_5fPONG_2eproto();  return *default_instance_;
}

PONG* PONG::default_instance_ = NULL;

PONG* PONG::New() const {
  return new PONG;
}

void PONG::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PONG::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
  return true;
#undef DO_
}

void PONG::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PONG::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PONG::ByteSize() const {
  int total_size = 0;
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PONG::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PONG* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PONG*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PONG::MergeFrom(const PONG& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PONG::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PONG::CopyFrom(const PONG& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PONG::IsInitialized() const {
  
  return true;
}

void PONG::Swap(PONG* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PONG::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PONG_descriptor_;
  metadata.reflection = PONG_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)