// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MSG_CS_DC_MEMORY_INFO_SEND.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MSG_CS_DC_MEMORY_INFO_SEND_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MSG_CS_DC_MEMORY_INFO_SEND_reflection_ = NULL;
const ::google::protobuf::Descriptor* MSG_DC_CS_MEMORY_INFO_SEND_ACK_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MSG_DC_CS_MEMORY_INFO_SEND_ACK_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto() {
  protobuf_AddDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MSG_CS_DC_MEMORY_INFO_SEND.proto");
  GOOGLE_CHECK(file != NULL);
  MSG_CS_DC_MEMORY_INFO_SEND_descriptor_ = file->message_type(0);
  static const int MSG_CS_DC_MEMORY_INFO_SEND_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_MEMORY_INFO_SEND, memory_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_MEMORY_INFO_SEND, port_),
  };
  MSG_CS_DC_MEMORY_INFO_SEND_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MSG_CS_DC_MEMORY_INFO_SEND_descriptor_,
      MSG_CS_DC_MEMORY_INFO_SEND::default_instance_,
      MSG_CS_DC_MEMORY_INFO_SEND_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_MEMORY_INFO_SEND, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_MEMORY_INFO_SEND, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MSG_CS_DC_MEMORY_INFO_SEND));
  MSG_DC_CS_MEMORY_INFO_SEND_ACK_descriptor_ = file->message_type(1);
  static const int MSG_DC_CS_MEMORY_INFO_SEND_ACK_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_MEMORY_INFO_SEND_ACK, statuscode_),
  };
  MSG_DC_CS_MEMORY_INFO_SEND_ACK_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MSG_DC_CS_MEMORY_INFO_SEND_ACK_descriptor_,
      MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance_,
      MSG_DC_CS_MEMORY_INFO_SEND_ACK_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_MEMORY_INFO_SEND_ACK, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_MEMORY_INFO_SEND_ACK, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MSG_DC_CS_MEMORY_INFO_SEND_ACK));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MSG_CS_DC_MEMORY_INFO_SEND_descriptor_, &MSG_CS_DC_MEMORY_INFO_SEND::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MSG_DC_CS_MEMORY_INFO_SEND_ACK_descriptor_, &MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto() {
  delete MSG_CS_DC_MEMORY_INFO_SEND::default_instance_;
  delete MSG_CS_DC_MEMORY_INFO_SEND_reflection_;
  delete MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance_;
  delete MSG_DC_CS_MEMORY_INFO_SEND_ACK_reflection_;
}

void protobuf_AddDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n MSG_CS_DC_MEMORY_INFO_SEND.proto\":\n\032MS"
    "G_CS_DC_MEMORY_INFO_SEND\022\016\n\006memory\030\001 \002(\r"
    "\022\014\n\004port\030\002 \002(\r\"4\n\036MSG_DC_CS_MEMORY_INFO_"
    "SEND_ACK\022\022\n\nstatusCode\030\001 \002(\r", 148);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MSG_CS_DC_MEMORY_INFO_SEND.proto", &protobuf_RegisterTypes);
  MSG_CS_DC_MEMORY_INFO_SEND::default_instance_ = new MSG_CS_DC_MEMORY_INFO_SEND();
  MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance_ = new MSG_DC_CS_MEMORY_INFO_SEND_ACK();
  MSG_CS_DC_MEMORY_INFO_SEND::default_instance_->InitAsDefaultInstance();
  MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto {
  StaticDescriptorInitializer_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto() {
    protobuf_AddDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto();
  }
} static_descriptor_initializer_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int MSG_CS_DC_MEMORY_INFO_SEND::kMemoryFieldNumber;
const int MSG_CS_DC_MEMORY_INFO_SEND::kPortFieldNumber;
#endif  // !_MSC_VER

MSG_CS_DC_MEMORY_INFO_SEND::MSG_CS_DC_MEMORY_INFO_SEND()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MSG_CS_DC_MEMORY_INFO_SEND::InitAsDefaultInstance() {
}

MSG_CS_DC_MEMORY_INFO_SEND::MSG_CS_DC_MEMORY_INFO_SEND(const MSG_CS_DC_MEMORY_INFO_SEND& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MSG_CS_DC_MEMORY_INFO_SEND::SharedCtor() {
  _cached_size_ = 0;
  memory_ = 0u;
  port_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MSG_CS_DC_MEMORY_INFO_SEND::~MSG_CS_DC_MEMORY_INFO_SEND() {
  SharedDtor();
}

void MSG_CS_DC_MEMORY_INFO_SEND::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MSG_CS_DC_MEMORY_INFO_SEND::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MSG_CS_DC_MEMORY_INFO_SEND::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MSG_CS_DC_MEMORY_INFO_SEND_descriptor_;
}

const MSG_CS_DC_MEMORY_INFO_SEND& MSG_CS_DC_MEMORY_INFO_SEND::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto();  return *default_instance_;
}

MSG_CS_DC_MEMORY_INFO_SEND* MSG_CS_DC_MEMORY_INFO_SEND::default_instance_ = NULL;

MSG_CS_DC_MEMORY_INFO_SEND* MSG_CS_DC_MEMORY_INFO_SEND::New() const {
  return new MSG_CS_DC_MEMORY_INFO_SEND;
}

void MSG_CS_DC_MEMORY_INFO_SEND::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    memory_ = 0u;
    port_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MSG_CS_DC_MEMORY_INFO_SEND::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 memory = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &memory_)));
          set_has_memory();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_port;
        break;
      }
      
      // required uint32 port = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_port:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &port_)));
          set_has_port();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MSG_CS_DC_MEMORY_INFO_SEND::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 memory = 1;
  if (has_memory()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->memory(), output);
  }
  
  // required uint32 port = 2;
  if (has_port()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->port(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MSG_CS_DC_MEMORY_INFO_SEND::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 memory = 1;
  if (has_memory()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->memory(), target);
  }
  
  // required uint32 port = 2;
  if (has_port()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->port(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MSG_CS_DC_MEMORY_INFO_SEND::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 memory = 1;
    if (has_memory()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->memory());
    }
    
    // required uint32 port = 2;
    if (has_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->port());
    }
    
  }
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

void MSG_CS_DC_MEMORY_INFO_SEND::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MSG_CS_DC_MEMORY_INFO_SEND* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MSG_CS_DC_MEMORY_INFO_SEND*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MSG_CS_DC_MEMORY_INFO_SEND::MergeFrom(const MSG_CS_DC_MEMORY_INFO_SEND& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_memory()) {
      set_memory(from.memory());
    }
    if (from.has_port()) {
      set_port(from.port());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MSG_CS_DC_MEMORY_INFO_SEND::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG_CS_DC_MEMORY_INFO_SEND::CopyFrom(const MSG_CS_DC_MEMORY_INFO_SEND& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG_CS_DC_MEMORY_INFO_SEND::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void MSG_CS_DC_MEMORY_INFO_SEND::Swap(MSG_CS_DC_MEMORY_INFO_SEND* other) {
  if (other != this) {
    std::swap(memory_, other->memory_);
    std::swap(port_, other->port_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MSG_CS_DC_MEMORY_INFO_SEND::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MSG_CS_DC_MEMORY_INFO_SEND_descriptor_;
  metadata.reflection = MSG_CS_DC_MEMORY_INFO_SEND_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MSG_DC_CS_MEMORY_INFO_SEND_ACK::kStatusCodeFieldNumber;
#endif  // !_MSC_VER

MSG_DC_CS_MEMORY_INFO_SEND_ACK::MSG_DC_CS_MEMORY_INFO_SEND_ACK()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::InitAsDefaultInstance() {
}

MSG_DC_CS_MEMORY_INFO_SEND_ACK::MSG_DC_CS_MEMORY_INFO_SEND_ACK(const MSG_DC_CS_MEMORY_INFO_SEND_ACK& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::SharedCtor() {
  _cached_size_ = 0;
  statuscode_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MSG_DC_CS_MEMORY_INFO_SEND_ACK::~MSG_DC_CS_MEMORY_INFO_SEND_ACK() {
  SharedDtor();
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MSG_DC_CS_MEMORY_INFO_SEND_ACK::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MSG_DC_CS_MEMORY_INFO_SEND_ACK_descriptor_;
}

const MSG_DC_CS_MEMORY_INFO_SEND_ACK& MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fCS_5fDC_5fMEMORY_5fINFO_5fSEND_2eproto();  return *default_instance_;
}

MSG_DC_CS_MEMORY_INFO_SEND_ACK* MSG_DC_CS_MEMORY_INFO_SEND_ACK::default_instance_ = NULL;

MSG_DC_CS_MEMORY_INFO_SEND_ACK* MSG_DC_CS_MEMORY_INFO_SEND_ACK::New() const {
  return new MSG_DC_CS_MEMORY_INFO_SEND_ACK;
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    statuscode_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MSG_DC_CS_MEMORY_INFO_SEND_ACK::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 statusCode = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &statuscode_)));
          set_has_statuscode();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 statusCode = 1;
  if (has_statuscode()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->statuscode(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MSG_DC_CS_MEMORY_INFO_SEND_ACK::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 statusCode = 1;
  if (has_statuscode()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->statuscode(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MSG_DC_CS_MEMORY_INFO_SEND_ACK::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 statusCode = 1;
    if (has_statuscode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->statuscode());
    }
    
  }
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

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MSG_DC_CS_MEMORY_INFO_SEND_ACK* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MSG_DC_CS_MEMORY_INFO_SEND_ACK*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::MergeFrom(const MSG_DC_CS_MEMORY_INFO_SEND_ACK& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_statuscode()) {
      set_statuscode(from.statuscode());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::CopyFrom(const MSG_DC_CS_MEMORY_INFO_SEND_ACK& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG_DC_CS_MEMORY_INFO_SEND_ACK::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  return true;
}

void MSG_DC_CS_MEMORY_INFO_SEND_ACK::Swap(MSG_DC_CS_MEMORY_INFO_SEND_ACK* other) {
  if (other != this) {
    std::swap(statuscode_, other->statuscode_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MSG_DC_CS_MEMORY_INFO_SEND_ACK::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MSG_DC_CS_MEMORY_INFO_SEND_ACK_descriptor_;
  metadata.reflection = MSG_DC_CS_MEMORY_INFO_SEND_ACK_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
