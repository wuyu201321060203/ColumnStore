// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MSG_CS_DC_COLUMN_POSITION_LOCATE.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MSG_CS_DC_COLUMN_POSITION_LOCATE_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MSG_CS_DC_COLUMN_POSITION_LOCATE_reflection_ = NULL;
const ::google::protobuf::Descriptor* MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto() {
  protobuf_AddDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MSG_CS_DC_COLUMN_POSITION_LOCATE.proto");
  GOOGLE_CHECK(file != NULL);
  MSG_CS_DC_COLUMN_POSITION_LOCATE_descriptor_ = file->message_type(0);
  static const int MSG_CS_DC_COLUMN_POSITION_LOCATE_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_COLUMN_POSITION_LOCATE, dbid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_COLUMN_POSITION_LOCATE, tablename_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_COLUMN_POSITION_LOCATE, columnname_),
  };
  MSG_CS_DC_COLUMN_POSITION_LOCATE_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MSG_CS_DC_COLUMN_POSITION_LOCATE_descriptor_,
      MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance_,
      MSG_CS_DC_COLUMN_POSITION_LOCATE_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_COLUMN_POSITION_LOCATE, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_DC_COLUMN_POSITION_LOCATE, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MSG_CS_DC_COLUMN_POSITION_LOCATE));
  MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_descriptor_ = file->message_type(1);
  static const int MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK, csip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK, statuscode_),
  };
  MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_descriptor_,
      MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance_,
      MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MSG_CS_DC_COLUMN_POSITION_LOCATE_descriptor_, &MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_descriptor_, &MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto() {
  delete MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance_;
  delete MSG_CS_DC_COLUMN_POSITION_LOCATE_reflection_;
  delete MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance_;
  delete MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_reflection_;
}

void protobuf_AddDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n&MSG_CS_DC_COLUMN_POSITION_LOCATE.proto"
    "\"W\n MSG_CS_DC_COLUMN_POSITION_LOCATE\022\014\n\004"
    "dbID\030\001 \001(\r\022\021\n\ttableName\030\002 \001(\t\022\022\n\ncolumnN"
    "ame\030\003 \001(\t\"H\n$MSG_DC_CS_COLUMN_POSITION_L"
    "OCATE_ACK\022\014\n\004csIP\030\001 \001(\t\022\022\n\nstatusCode\030\002 "
    "\001(\005", 203);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MSG_CS_DC_COLUMN_POSITION_LOCATE.proto", &protobuf_RegisterTypes);
  MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance_ = new MSG_CS_DC_COLUMN_POSITION_LOCATE();
  MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance_ = new MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK();
  MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance_->InitAsDefaultInstance();
  MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto {
  StaticDescriptorInitializer_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto() {
    protobuf_AddDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto();
  }
} static_descriptor_initializer_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int MSG_CS_DC_COLUMN_POSITION_LOCATE::kDbIDFieldNumber;
const int MSG_CS_DC_COLUMN_POSITION_LOCATE::kTableNameFieldNumber;
const int MSG_CS_DC_COLUMN_POSITION_LOCATE::kColumnNameFieldNumber;
#endif  // !_MSC_VER

MSG_CS_DC_COLUMN_POSITION_LOCATE::MSG_CS_DC_COLUMN_POSITION_LOCATE()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::InitAsDefaultInstance() {
}

MSG_CS_DC_COLUMN_POSITION_LOCATE::MSG_CS_DC_COLUMN_POSITION_LOCATE(const MSG_CS_DC_COLUMN_POSITION_LOCATE& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::SharedCtor() {
  _cached_size_ = 0;
  dbid_ = 0u;
  tablename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  columnname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MSG_CS_DC_COLUMN_POSITION_LOCATE::~MSG_CS_DC_COLUMN_POSITION_LOCATE() {
  SharedDtor();
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::SharedDtor() {
  if (tablename_ != &::google::protobuf::internal::kEmptyString) {
    delete tablename_;
  }
  if (columnname_ != &::google::protobuf::internal::kEmptyString) {
    delete columnname_;
  }
  if (this != default_instance_) {
  }
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MSG_CS_DC_COLUMN_POSITION_LOCATE::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MSG_CS_DC_COLUMN_POSITION_LOCATE_descriptor_;
}

const MSG_CS_DC_COLUMN_POSITION_LOCATE& MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto();  return *default_instance_;
}

MSG_CS_DC_COLUMN_POSITION_LOCATE* MSG_CS_DC_COLUMN_POSITION_LOCATE::default_instance_ = NULL;

MSG_CS_DC_COLUMN_POSITION_LOCATE* MSG_CS_DC_COLUMN_POSITION_LOCATE::New() const {
  return new MSG_CS_DC_COLUMN_POSITION_LOCATE;
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    dbid_ = 0u;
    if (has_tablename()) {
      if (tablename_ != &::google::protobuf::internal::kEmptyString) {
        tablename_->clear();
      }
    }
    if (has_columnname()) {
      if (columnname_ != &::google::protobuf::internal::kEmptyString) {
        columnname_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MSG_CS_DC_COLUMN_POSITION_LOCATE::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 dbID = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &dbid_)));
          set_has_dbid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_tableName;
        break;
      }
      
      // optional string tableName = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tableName:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_tablename()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->tablename().data(), this->tablename().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_columnName;
        break;
      }
      
      // optional string columnName = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_columnName:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_columnname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->columnname().data(), this->columnname().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
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

void MSG_CS_DC_COLUMN_POSITION_LOCATE::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional uint32 dbID = 1;
  if (has_dbid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->dbid(), output);
  }
  
  // optional string tableName = 2;
  if (has_tablename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->tablename().data(), this->tablename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->tablename(), output);
  }
  
  // optional string columnName = 3;
  if (has_columnname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->columnname().data(), this->columnname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->columnname(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MSG_CS_DC_COLUMN_POSITION_LOCATE::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional uint32 dbID = 1;
  if (has_dbid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->dbid(), target);
  }
  
  // optional string tableName = 2;
  if (has_tablename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->tablename().data(), this->tablename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->tablename(), target);
  }
  
  // optional string columnName = 3;
  if (has_columnname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->columnname().data(), this->columnname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->columnname(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MSG_CS_DC_COLUMN_POSITION_LOCATE::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 dbID = 1;
    if (has_dbid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->dbid());
    }
    
    // optional string tableName = 2;
    if (has_tablename()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->tablename());
    }
    
    // optional string columnName = 3;
    if (has_columnname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->columnname());
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

void MSG_CS_DC_COLUMN_POSITION_LOCATE::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MSG_CS_DC_COLUMN_POSITION_LOCATE* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MSG_CS_DC_COLUMN_POSITION_LOCATE*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::MergeFrom(const MSG_CS_DC_COLUMN_POSITION_LOCATE& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_dbid()) {
      set_dbid(from.dbid());
    }
    if (from.has_tablename()) {
      set_tablename(from.tablename());
    }
    if (from.has_columnname()) {
      set_columnname(from.columnname());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::CopyFrom(const MSG_CS_DC_COLUMN_POSITION_LOCATE& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG_CS_DC_COLUMN_POSITION_LOCATE::IsInitialized() const {
  
  return true;
}

void MSG_CS_DC_COLUMN_POSITION_LOCATE::Swap(MSG_CS_DC_COLUMN_POSITION_LOCATE* other) {
  if (other != this) {
    std::swap(dbid_, other->dbid_);
    std::swap(tablename_, other->tablename_);
    std::swap(columnname_, other->columnname_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MSG_CS_DC_COLUMN_POSITION_LOCATE::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MSG_CS_DC_COLUMN_POSITION_LOCATE_descriptor_;
  metadata.reflection = MSG_CS_DC_COLUMN_POSITION_LOCATE_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::kCsIPFieldNumber;
const int MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::kStatusCodeFieldNumber;
#endif  // !_MSC_VER

MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::InitAsDefaultInstance() {
}

MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK(const MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::SharedCtor() {
  _cached_size_ = 0;
  csip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  statuscode_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::~MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK() {
  SharedDtor();
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::SharedDtor() {
  if (csip_ != &::google::protobuf::internal::kEmptyString) {
    delete csip_;
  }
  if (this != default_instance_) {
  }
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_descriptor_;
}

const MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK& MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fCS_5fDC_5fCOLUMN_5fPOSITION_5fLOCATE_2eproto();  return *default_instance_;
}

MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK* MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::default_instance_ = NULL;

MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK* MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::New() const {
  return new MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK;
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_csip()) {
      if (csip_ != &::google::protobuf::internal::kEmptyString) {
        csip_->clear();
      }
    }
    statuscode_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string csIP = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_csip()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->csip().data(), this->csip().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_statusCode;
        break;
      }
      
      // optional int32 statusCode = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_statusCode:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
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

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional string csIP = 1;
  if (has_csip()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->csip().data(), this->csip().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->csip(), output);
  }
  
  // optional int32 statusCode = 2;
  if (has_statuscode()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->statuscode(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional string csIP = 1;
  if (has_csip()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->csip().data(), this->csip().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->csip(), target);
  }
  
  // optional int32 statusCode = 2;
  if (has_statuscode()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->statuscode(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string csIP = 1;
    if (has_csip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->csip());
    }
    
    // optional int32 statusCode = 2;
    if (has_statuscode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
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

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::MergeFrom(const MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_csip()) {
      set_csip(from.csip());
    }
    if (from.has_statuscode()) {
      set_statuscode(from.statuscode());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::CopyFrom(const MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::IsInitialized() const {
  
  return true;
}

void MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::Swap(MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK* other) {
  if (other != this) {
    std::swap(csip_, other->csip_);
    std::swap(statuscode_, other->statuscode_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_descriptor_;
  metadata.reflection = MSG_DC_CS_COLUMN_POSITION_LOCATE_ACK_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)