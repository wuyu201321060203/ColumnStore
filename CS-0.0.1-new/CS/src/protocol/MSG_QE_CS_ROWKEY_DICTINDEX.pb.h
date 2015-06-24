// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSG_QE_CS_ROWKEY_DICTINDEX.proto

#ifndef PROTOBUF_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto__INCLUDED
#define PROTOBUF_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
void protobuf_AssignDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
void protobuf_ShutdownFile_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();

class MSG_QE_CS_ROWKEY_DICTINDEX;
class MSG_CS_QE_ROWKEY_DICTINDEX_ACK;

// ===================================================================

class MSG_QE_CS_ROWKEY_DICTINDEX : public ::google::protobuf::Message {
 public:
  MSG_QE_CS_ROWKEY_DICTINDEX();
  virtual ~MSG_QE_CS_ROWKEY_DICTINDEX();
  
  MSG_QE_CS_ROWKEY_DICTINDEX(const MSG_QE_CS_ROWKEY_DICTINDEX& from);
  
  inline MSG_QE_CS_ROWKEY_DICTINDEX& operator=(const MSG_QE_CS_ROWKEY_DICTINDEX& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const MSG_QE_CS_ROWKEY_DICTINDEX& default_instance();
  
  void Swap(MSG_QE_CS_ROWKEY_DICTINDEX* other);
  
  // implements Message ----------------------------------------------
  
  MSG_QE_CS_ROWKEY_DICTINDEX* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_QE_CS_ROWKEY_DICTINDEX& from);
  void MergeFrom(const MSG_QE_CS_ROWKEY_DICTINDEX& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required uint32 db_id = 1;
  inline bool has_db_id() const;
  inline void clear_db_id();
  static const int kDbIdFieldNumber = 1;
  inline ::google::protobuf::uint32 db_id() const;
  inline void set_db_id(::google::protobuf::uint32 value);
  
  // required string tablename = 2;
  inline bool has_tablename() const;
  inline void clear_tablename();
  static const int kTablenameFieldNumber = 2;
  inline const ::std::string& tablename() const;
  inline void set_tablename(const ::std::string& value);
  inline void set_tablename(const char* value);
  inline void set_tablename(const char* value, size_t size);
  inline ::std::string* mutable_tablename();
  inline ::std::string* release_tablename();
  
  // required string columnname = 3;
  inline bool has_columnname() const;
  inline void clear_columnname();
  static const int kColumnnameFieldNumber = 3;
  inline const ::std::string& columnname() const;
  inline void set_columnname(const ::std::string& value);
  inline void set_columnname(const char* value);
  inline void set_columnname(const char* value, size_t size);
  inline ::std::string* mutable_columnname();
  inline ::std::string* release_columnname();
  
  // required string rowkeys = 4;
  inline bool has_rowkeys() const;
  inline void clear_rowkeys();
  static const int kRowkeysFieldNumber = 4;
  inline const ::std::string& rowkeys() const;
  inline void set_rowkeys(const ::std::string& value);
  inline void set_rowkeys(const char* value);
  inline void set_rowkeys(const char* value, size_t size);
  inline ::std::string* mutable_rowkeys();
  inline ::std::string* release_rowkeys();
  
  // required bool is_local = 5;
  inline bool has_is_local() const;
  inline void clear_is_local();
  static const int kIsLocalFieldNumber = 5;
  inline bool is_local() const;
  inline void set_is_local(bool value);
  
  // @@protoc_insertion_point(class_scope:MSG_QE_CS_ROWKEY_DICTINDEX)
 private:
  inline void set_has_db_id();
  inline void clear_has_db_id();
  inline void set_has_tablename();
  inline void clear_has_tablename();
  inline void set_has_columnname();
  inline void clear_has_columnname();
  inline void set_has_rowkeys();
  inline void clear_has_rowkeys();
  inline void set_has_is_local();
  inline void clear_has_is_local();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* tablename_;
  ::std::string* columnname_;
  ::google::protobuf::uint32 db_id_;
  bool is_local_;
  ::std::string* rowkeys_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  friend void protobuf_AssignDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_QE_CS_ROWKEY_DICTINDEX* default_instance_;
};
// -------------------------------------------------------------------

class MSG_CS_QE_ROWKEY_DICTINDEX_ACK : public ::google::protobuf::Message {
 public:
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK();
  virtual ~MSG_CS_QE_ROWKEY_DICTINDEX_ACK();
  
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from);
  
  inline MSG_CS_QE_ROWKEY_DICTINDEX_ACK& operator=(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& default_instance();
  
  void Swap(MSG_CS_QE_ROWKEY_DICTINDEX_ACK* other);
  
  // implements Message ----------------------------------------------
  
  MSG_CS_QE_ROWKEY_DICTINDEX_ACK* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from);
  void MergeFrom(const MSG_CS_QE_ROWKEY_DICTINDEX_ACK& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 status_code = 1;
  inline bool has_status_code() const;
  inline void clear_status_code();
  static const int kStatusCodeFieldNumber = 1;
  inline ::google::protobuf::int32 status_code() const;
  inline void set_status_code(::google::protobuf::int32 value);
  
  // optional string dict_index = 2;
  inline bool has_dict_index() const;
  inline void clear_dict_index();
  static const int kDictIndexFieldNumber = 2;
  inline const ::std::string& dict_index() const;
  inline void set_dict_index(const ::std::string& value);
  inline void set_dict_index(const char* value);
  inline void set_dict_index(const char* value, size_t size);
  inline ::std::string* mutable_dict_index();
  inline ::std::string* release_dict_index();
  
  // optional uint32 shm_size = 3;
  inline bool has_shm_size() const;
  inline void clear_shm_size();
  static const int kShmSizeFieldNumber = 3;
  inline ::google::protobuf::uint32 shm_size() const;
  inline void set_shm_size(::google::protobuf::uint32 value);
  
  // @@protoc_insertion_point(class_scope:MSG_CS_QE_ROWKEY_DICTINDEX_ACK)
 private:
  inline void set_has_status_code();
  inline void clear_has_status_code();
  inline void set_has_dict_index();
  inline void clear_has_dict_index();
  inline void set_has_shm_size();
  inline void clear_has_shm_size();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* dict_index_;
  ::google::protobuf::int32 status_code_;
  ::google::protobuf::uint32 shm_size_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  friend void protobuf_AssignDesc_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_CS_QE_ROWKEY_DICTINDEX_ACK* default_instance_;
};
// ===================================================================


// ===================================================================

// MSG_QE_CS_ROWKEY_DICTINDEX

// required uint32 db_id = 1;
inline bool MSG_QE_CS_ROWKEY_DICTINDEX::has_db_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_has_db_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_has_db_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_db_id() {
  db_id_ = 0u;
  clear_has_db_id();
}
inline ::google::protobuf::uint32 MSG_QE_CS_ROWKEY_DICTINDEX::db_id() const {
  return db_id_;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_db_id(::google::protobuf::uint32 value) {
  set_has_db_id();
  db_id_ = value;
}

// required string tablename = 2;
inline bool MSG_QE_CS_ROWKEY_DICTINDEX::has_tablename() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_has_tablename() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_has_tablename() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_tablename() {
  if (tablename_ != &::google::protobuf::internal::kEmptyString) {
    tablename_->clear();
  }
  clear_has_tablename();
}
inline const ::std::string& MSG_QE_CS_ROWKEY_DICTINDEX::tablename() const {
  return *tablename_;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_tablename(const ::std::string& value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_tablename(const char* value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_tablename(const char* value, size_t size) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_QE_CS_ROWKEY_DICTINDEX::mutable_tablename() {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  return tablename_;
}
inline ::std::string* MSG_QE_CS_ROWKEY_DICTINDEX::release_tablename() {
  clear_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = tablename_;
    tablename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string columnname = 3;
inline bool MSG_QE_CS_ROWKEY_DICTINDEX::has_columnname() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_has_columnname() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_has_columnname() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_columnname() {
  if (columnname_ != &::google::protobuf::internal::kEmptyString) {
    columnname_->clear();
  }
  clear_has_columnname();
}
inline const ::std::string& MSG_QE_CS_ROWKEY_DICTINDEX::columnname() const {
  return *columnname_;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_columnname(const ::std::string& value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_columnname(const char* value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_columnname(const char* value, size_t size) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_QE_CS_ROWKEY_DICTINDEX::mutable_columnname() {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  return columnname_;
}
inline ::std::string* MSG_QE_CS_ROWKEY_DICTINDEX::release_columnname() {
  clear_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = columnname_;
    columnname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string rowkeys = 4;
inline bool MSG_QE_CS_ROWKEY_DICTINDEX::has_rowkeys() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_has_rowkeys() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_has_rowkeys() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_rowkeys() {
  if (rowkeys_ != &::google::protobuf::internal::kEmptyString) {
    rowkeys_->clear();
  }
  clear_has_rowkeys();
}
inline const ::std::string& MSG_QE_CS_ROWKEY_DICTINDEX::rowkeys() const {
  return *rowkeys_;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_rowkeys(const ::std::string& value) {
  set_has_rowkeys();
  if (rowkeys_ == &::google::protobuf::internal::kEmptyString) {
    rowkeys_ = new ::std::string;
  }
  rowkeys_->assign(value);
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_rowkeys(const char* value) {
  set_has_rowkeys();
  if (rowkeys_ == &::google::protobuf::internal::kEmptyString) {
    rowkeys_ = new ::std::string;
  }
  rowkeys_->assign(value);
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_rowkeys(const char* value, size_t size) {
  set_has_rowkeys();
  if (rowkeys_ == &::google::protobuf::internal::kEmptyString) {
    rowkeys_ = new ::std::string;
  }
  rowkeys_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_QE_CS_ROWKEY_DICTINDEX::mutable_rowkeys() {
  set_has_rowkeys();
  if (rowkeys_ == &::google::protobuf::internal::kEmptyString) {
    rowkeys_ = new ::std::string;
  }
  return rowkeys_;
}
inline ::std::string* MSG_QE_CS_ROWKEY_DICTINDEX::release_rowkeys() {
  clear_has_rowkeys();
  if (rowkeys_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = rowkeys_;
    rowkeys_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required bool is_local = 5;
inline bool MSG_QE_CS_ROWKEY_DICTINDEX::has_is_local() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_has_is_local() {
  _has_bits_[0] |= 0x00000010u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_has_is_local() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::clear_is_local() {
  is_local_ = false;
  clear_has_is_local();
}
inline bool MSG_QE_CS_ROWKEY_DICTINDEX::is_local() const {
  return is_local_;
}
inline void MSG_QE_CS_ROWKEY_DICTINDEX::set_is_local(bool value) {
  set_has_is_local();
  is_local_ = value;
}

// -------------------------------------------------------------------

// MSG_CS_QE_ROWKEY_DICTINDEX_ACK

// required int32 status_code = 1;
inline bool MSG_CS_QE_ROWKEY_DICTINDEX_ACK::has_status_code() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_has_status_code() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::clear_has_status_code() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::clear_status_code() {
  status_code_ = 0;
  clear_has_status_code();
}
inline ::google::protobuf::int32 MSG_CS_QE_ROWKEY_DICTINDEX_ACK::status_code() const {
  return status_code_;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_status_code(::google::protobuf::int32 value) {
  set_has_status_code();
  status_code_ = value;
}

// optional string dict_index = 2;
inline bool MSG_CS_QE_ROWKEY_DICTINDEX_ACK::has_dict_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_has_dict_index() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::clear_has_dict_index() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::clear_dict_index() {
  if (dict_index_ != &::google::protobuf::internal::kEmptyString) {
    dict_index_->clear();
  }
  clear_has_dict_index();
}
inline const ::std::string& MSG_CS_QE_ROWKEY_DICTINDEX_ACK::dict_index() const {
  return *dict_index_;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_dict_index(const ::std::string& value) {
  set_has_dict_index();
  if (dict_index_ == &::google::protobuf::internal::kEmptyString) {
    dict_index_ = new ::std::string;
  }
  dict_index_->assign(value);
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_dict_index(const char* value) {
  set_has_dict_index();
  if (dict_index_ == &::google::protobuf::internal::kEmptyString) {
    dict_index_ = new ::std::string;
  }
  dict_index_->assign(value);
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_dict_index(const char* value, size_t size) {
  set_has_dict_index();
  if (dict_index_ == &::google::protobuf::internal::kEmptyString) {
    dict_index_ = new ::std::string;
  }
  dict_index_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_CS_QE_ROWKEY_DICTINDEX_ACK::mutable_dict_index() {
  set_has_dict_index();
  if (dict_index_ == &::google::protobuf::internal::kEmptyString) {
    dict_index_ = new ::std::string;
  }
  return dict_index_;
}
inline ::std::string* MSG_CS_QE_ROWKEY_DICTINDEX_ACK::release_dict_index() {
  clear_has_dict_index();
  if (dict_index_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = dict_index_;
    dict_index_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional uint32 shm_size = 3;
inline bool MSG_CS_QE_ROWKEY_DICTINDEX_ACK::has_shm_size() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_has_shm_size() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::clear_has_shm_size() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::clear_shm_size() {
  shm_size_ = 0u;
  clear_has_shm_size();
}
inline ::google::protobuf::uint32 MSG_CS_QE_ROWKEY_DICTINDEX_ACK::shm_size() const {
  return shm_size_;
}
inline void MSG_CS_QE_ROWKEY_DICTINDEX_ACK::set_shm_size(::google::protobuf::uint32 value) {
  set_has_shm_size();
  shm_size_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MSG_5fQE_5fCS_5fROWKEY_5fDICTINDEX_2eproto__INCLUDED