// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MSG_QE_CS_ROWKEY_DICTINDEX.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MSG_QE_CS_ROWKEY_DICTINDEX_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MSG_QE_CS_ROWKEY_DICTINDEX_reflection_ = NULL;
const ::google::protobuf::Descriptor* MSG_CS_QE_ROWKEY_DICTINDEX_ACK_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto() {
  protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MSG_QE_CS_ROWKEY_DICTINDEX.proto");
  GOOGLE_CHECK(file != NULL);
  MSG_QE_CS_ROWKEY_DICTINDEX_descriptor_ = file->message_type(0);
  static const int MSG_QE_CS_ROWKEY_DICTINDEX_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, db_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, tablename_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, columnname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, rowkeys_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, is_local_),
  };
  MSG_QE_CS_ROWKEY_DICTINDEX_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MSG_QE_CS_ROWKEY_DICTINDEX_descriptor_,
      MSG_QE_CS_ROWKEY_DICTINDEX::default_instance_,
      MSG_QE_CS_ROWKEY_DICTINDEX_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_QE_CS_ROWKEY_DICTINDEX, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MSG_QE_CS_ROWKEY_DICTINDEX));
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK_descriptor_ = file->message_type(1);
  static const int MSG_CS_QE_ROWKEY_DICTINDEX_ACK_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_QE_ROWKEY_DICTINDEX_ACK, status_code_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_QE_ROWKEY_DICTINDEX_ACK, dict_index_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_QE_ROWKEY_DICTINDEX_ACK, shm_size_),
  };
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MSG_CS_QE_ROWKEY_DICTINDEX_ACK_descriptor_,
      MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance_,
      MSG_CS_QE_ROWKEY_DICTINDEX_ACK_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_QE_ROWKEY_DICTINDEX_ACK, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MSG_CS_QE_ROWKEY_DICTINDEX_ACK, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MSG_CS_QE_ROWKEY_DICTINDEX_ACK));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MSG_QE_CS_ROWKEY_DICTINDEX_descriptor_, &MSG_QE_CS_ROWKEY_DICTINDEX::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MSG_CS_QE_ROWKEY_DICTINDEX_ACK_descriptor_, &MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto() {
  delete MSG_QE_CS_ROWKEY_DICTINDEX::default_instance_;
  delete MSG_QE_CS_ROWKEY_DICTINDEX_reflection_;
  delete MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance_;
  delete MSG_CS_QE_ROWKEY_DICTINDEX_ACK_reflection_;
}

void protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n MSG_QE_CS_ROWKEY_DICTINDEX.proto\"u\n\032MS"
    "G_QE_CS_ROWKEY_DICTINDEX\022\r\n\005db_id\030\001 \002(\r\022"
    "\021\n\ttablename\030\002 \002(\t\022\022\n\ncolumnname\030\003 \002(\t\022\017"
    "\n\007rowkeys\030\004 \002(\t\022\020\n\010is_local\030\005 \002(\010\"[\n\036MSG"
    "_CS_QE_ROWKEY_DICTINDEX_ACK\022\023\n\013status_co"
    "de\030\001 \002(\005\022\022\n\ndict_index\030\002 \001(\t\022\020\n\010shm_size"
    "\030\003 \001(\r", 246);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MSG_QE_CS_ROWKEY_DICTINDEX.proto", &protobuf_RegisterTypes);
  MSG_QE_CS_ROWKEY_DICTINDEX::default_instance_ = new MSG_QE_CS_ROWKEY_DICTINDEX();
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance_ = new MSG_CS_QE_ROWKEY_DICTINDEX_ACK();
  MSG_QE_CS_ROWKEY_DICTINDEX::default_instance_->InitAsDefaultInstance();
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto {
  StaticDescriptorInitializer_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto() {
    protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  }
} static_descriptor_initializer_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int MSG_QE_CS_ROWKEY_DICTINDEX::kDbIdFieldNumber;
const int MSG_QE_CS_ROWKEY_DICTINDEX::kTablenameFieldNumber;
const int MSG_QE_CS_ROWKEY_DICTINDEX::kColumnnameFieldNumber;
const int MSG_QE_CS_ROWKEY_DICTINDEX::kRowkeysFieldNumber;
const int MSG_QE_CS_ROWKEY_DICTINDEX::kIsLocalFieldNumber;
#endif  // !_MSC_VER

MSG_QE_CS_ROWKEY_DICTINDEX::MSG_QE_CS_ROWKEY_DICTINDEX()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MSG_QE_CS_ROWKEY_DICTINDEX::InitAsDefaultInstance() {
}

MSG_QE_CS_ROWKEY_DICTINDEX::MSG_QE_CS_ROWKEY_DICTINDEX(const MSG_QE_CS_ROWKEY_DICTINDEX& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MSG_QE_CS_ROWKEY_DICTINDEX::SharedCtor() {
  _cached_size_ = 0;
  db_id_ = 0u;
  tablename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  columnname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  rowkeys_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  is_local_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MSG_QE_CS_ROWKEY_DICTINDEX::~MSG_QE_CS_ROWKEY_DICTINDEX() {
  SharedDtor();
}

void MSG_QE_CS_ROWKEY_DICTINDEX::SharedDtor() {
  if (tablename_ != &::google::protobuf::internal::kEmptyString) {
    delete tablename_;
  }
  if (columnname_ != &::google::protobuf::internal::kEmptyString) {
    delete columnname_;
  }
  if (rowkeys_ != &::google::protobuf::internal::kEmptyString) {
    delete rowkeys_;
  }
  if (this != default_instance_) {
  }
}

void MSG_QE_CS_ROWKEY_DICTINDEX::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MSG_QE_CS_ROWKEY_DICTINDEX::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MSG_QE_CS_ROWKEY_DICTINDEX_descriptor_;
}

const MSG_QE_CS_ROWKEY_DICTINDEX& MSG_QE_CS_ROWKEY_DICTINDEX::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();  return *default_instance_;
}

MSG_QE_CS_ROWKEY_DICTINDEX* MSG_QE_CS_ROWKEY_DICTINDEX::default_instance_ = NULL;

MSG_QE_CS_ROWKEY_DICTINDEX* MSG_QE_CS_ROWKEY_DICTINDEX::New() const {
  return new MSG_QE_CS_ROWKEY_DICTINDEX;
}

void MSG_QE_CS_ROWKEY_DICTINDEX::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    db_id_ = 0u;
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
    if (has_rowkeys()) {
      if (rowkeys_ != &::google::protobuf::internal::kEmptyString) {
        rowkeys_->clear();
      }
    }
    is_local_ = false;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MSG_QE_CS_ROWKEY_DICTINDEX::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 db_id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &db_id_)));
          set_has_db_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_tablename;
        break;
      }
      
      // required string tablename = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_tablename:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_tablename()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->tablename().data(), this->tablename().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_columnname;
        break;
      }
      
      // required string columnname = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_columnname:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_columnname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->columnname().data(), this->columnname().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_rowkeys;
        break;
      }
      
      // required string rowkeys = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_rowkeys:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_rowkeys()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->rowkeys().data(), this->rowkeys().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_is_local;
        break;
      }
      
      // required bool is_local = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_is_local:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_local_)));
          set_has_is_local();
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

void MSG_QE_CS_ROWKEY_DICTINDEX::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 db_id = 1;
  if (has_db_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->db_id(), output);
  }
  
  // required string tablename = 2;
  if (has_tablename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->tablename().data(), this->tablename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->tablename(), output);
  }
  
  // required string columnname = 3;
  if (has_columnname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->columnname().data(), this->columnname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->columnname(), output);
  }
  
  // required string rowkeys = 4;
  if (has_rowkeys()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->rowkeys().data(), this->rowkeys().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->rowkeys(), output);
  }
  
  // required bool is_local = 5;
  if (has_is_local()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->is_local(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MSG_QE_CS_ROWKEY_DICTINDEX::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 db_id = 1;
  if (has_db_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->db_id(), target);
  }
  
  // required string tablename = 2;
  if (has_tablename()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->tablename().data(), this->tablename().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->tablename(), target);
  }
  
  // required string columnname = 3;
  if (has_columnname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->columnname().data(), this->columnname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->columnname(), target);
  }
  
  // required string rowkeys = 4;
  if (has_rowkeys()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->rowkeys().data(), this->rowkeys().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->rowkeys(), target);
  }
  
  // required bool is_local = 5;
  if (has_is_local()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->is_local(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MSG_QE_CS_ROWKEY_DICTINDEX::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 db_id = 1;
    if (has_db_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->db_id());
    }
    
    // required string tablename = 2;
    if (has_tablename()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->tablename());
    }
    
    // required string columnname = 3;
    if (has_columnname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->columnname());
    }
    
    // required string rowkeys = 4;
    if (has_rowkeys()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->rowkeys());
    }
    
    // required bool is_local = 5;
    if (has_is_local()) {
      total_size += 1 + 1;
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

void MSG_QE_CS_ROWKEY_DICTINDEX::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MSG_QE_CS_ROWKEY_DICTINDEX* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MSG_QE_CS_ROWKEY_DICTINDEX*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MSG_QE_CS_ROWKEY_DICTINDEX::MergeFrom(const MSG_QE_CS_ROWKEY_DICTINDEX& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_db_id()) {
      set_db_id(from.db_id());
    }
    if (from.has_tablename()) {
      set_tablename(from.tablename());
    }
    if (from.has_columnname()) {
      set_columnname(from.columnname());
    }
    if (from.has_rowkeys()) {
      set_rowkeys(from.rowkeys());
    }
    if (from.has_is_local()) {
      set_is_local(from.is_local());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MSG_QE_CS_ROWKEY_DICTINDEX::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG_QE_CS_ROWKEY_DICTINDEX::CopyFrom(const MSG_QE_CS_ROWKEY_DICTINDEX& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG_QE_CS_ROWKEY_DICTINDEX::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;
  
  return true;
}

void MSG_QE_CS_ROWKEY_DICTINDEX::Swap(MSG_QE_CS_ROWKEY_DICTINDEX* other) {
  if (other != this) {
    std::swap(db_id_, other->db_id_);
    std::swap(tablename_, other->tablename_);
    std::swap(columnname_, other->columnname_);
    std::swap(rowkeys_, other->rowkeys_);
    std::swap(is_local_, other->is_local_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MSG_QE_CS_ROWKEY_DICTINDEX::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MSG_QE_CS_ROWKEY_DICTINDEX_descriptor_;
  metadata.reflection = MSG_QE_CS_ROWKEY_DICTINDEX_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MSG_CS_QE_ROWKEY_DICTINDEX_ACK::kStatusCodeFieldNumber;
const int MSG_CS_QE_ROWKEY_DICTINDEX_ACK::kDictIndexFieldNumber;
const int MSG_CS_QE_ROWKEY_DICTINDEX_ACK::kShmSizeFieldNumber;
#endif  // !_MSC_VER

MSG_CS_QE_ROWKEY_DICTINDEX_ACK::MSG_CS_QE_ROWKEY_DICTINDEX_ACK()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::InitAsDefaultInstance() {
}

MSG_CS_QE_ROWKEY_DICTINDEX_ACK::MSG_CS_QE_ROWKEY_DICTINDEX_ACK(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::SharedCtor() {
  _cached_size_ = 0;
  status_code_ = 0;
  dict_index_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  shm_size_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MSG_CS_QE_ROWKEY_DICTINDEX_ACK::~MSG_CS_QE_ROWKEY_DICTINDEX_ACK() {
  SharedDtor();
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::SharedDtor() {
  if (dict_index_ != &::google::protobuf::internal::kEmptyString) {
    delete dict_index_;
  }
  if (this != default_instance_) {
  }
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MSG_CS_QE_ROWKEY_DICTINDEX_ACK::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MSG_CS_QE_ROWKEY_DICTINDEX_ACK_descriptor_;
}

const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();  return *default_instance_;
}

MSG_CS_QE_ROWKEY_DICTINDEX_ACK* MSG_CS_QE_ROWKEY_DICTINDEX_ACK::default_instance_ = NULL;

MSG_CS_QE_ROWKEY_DICTINDEX_ACK* MSG_CS_QE_ROWKEY_DICTINDEX_ACK::New() const {
  return new MSG_CS_QE_ROWKEY_DICTINDEX_ACK;
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    status_code_ = 0;
    if (has_dict_index()) {
      if (dict_index_ != &::google::protobuf::internal::kEmptyString) {
        dict_index_->clear();
      }
    }
    shm_size_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MSG_CS_QE_ROWKEY_DICTINDEX_ACK::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 status_code = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &status_code_)));
          set_has_status_code();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_dict_index;
        break;
      }
      
      // optional string dict_index = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_dict_index:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_dict_index()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->dict_index().data(), this->dict_index().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_shm_size;
        break;
      }
      
      // optional uint32 shm_size = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_shm_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &shm_size_)));
          set_has_shm_size();
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

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 status_code = 1;
  if (has_status_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->status_code(), output);
  }
  
  // optional string dict_index = 2;
  if (has_dict_index()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->dict_index().data(), this->dict_index().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->dict_index(), output);
  }
  
  // optional uint32 shm_size = 3;
  if (has_shm_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->shm_size(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MSG_CS_QE_ROWKEY_DICTINDEX_ACK::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 status_code = 1;
  if (has_status_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->status_code(), target);
  }
  
  // optional string dict_index = 2;
  if (has_dict_index()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->dict_index().data(), this->dict_index().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->dict_index(), target);
  }
  
  // optional uint32 shm_size = 3;
  if (has_shm_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->shm_size(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MSG_CS_QE_ROWKEY_DICTINDEX_ACK::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 status_code = 1;
    if (has_status_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->status_code());
    }
    
    // optional string dict_index = 2;
    if (has_dict_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->dict_index());
    }
    
    // optional uint32 shm_size = 3;
    if (has_shm_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->shm_size());
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

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MSG_CS_QE_ROWKEY_DICTINDEX_ACK* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MSG_CS_QE_ROWKEY_DICTINDEX_ACK*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::MergeFrom(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_status_code()) {
      set_status_code(from.status_code());
    }
    if (from.has_dict_index()) {
      set_dict_index(from.dict_index());
    }
    if (from.has_shm_size()) {
      set_shm_size(from.shm_size());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::CopyFrom(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG_CS_QE_ROWKEY_DICTINDEX_ACK::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;
  
  return true;
}

void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::Swap(MSG_CS_QE_ROWKEY_DICTINDEX_ACK* other) {
  if (other != this) {
    std::swap(status_code_, other->status_code_);
    std::swap(dict_index_, other->dict_index_);
    std::swap(shm_size_, other->shm_size_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MSG_CS_QE_ROWKEY_DICTINDEX_ACK::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MSG_CS_QE_ROWKEY_DICTINDEX_ACK_descriptor_;
  metadata.reflection = MSG_CS_QE_ROWKEY_DICTINDEX_ACK_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)