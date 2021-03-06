// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSG_DS_CS_RTABLE_CREATE.proto

#ifndef PROTOBUF_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto__INCLUDED
#define PROTOBUF_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto__INCLUDED

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
void  protobuf_AddDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
void protobuf_AssignDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
void protobuf_ShutdownFile_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();

class MSG_DS_CS_RTABLE_CREATE;
class MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE;
class MSG_CS_DS_RTABLE_CREATE_ACK;

// ===================================================================

class MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE : public ::google::protobuf::Message {
 public:
  MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE();
  virtual ~MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE();
  
  MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE(const MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& from);
  
  inline MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& operator=(const MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& from) {
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
  static const MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& default_instance();
  
  void Swap(MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* other);
  
  // implements Message ----------------------------------------------
  
  MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& from);
  void MergeFrom(const MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& from);
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
  
  // optional string columnName = 1;
  inline bool has_columnname() const;
  inline void clear_columnname();
  static const int kColumnNameFieldNumber = 1;
  inline const ::std::string& columnname() const;
  inline void set_columnname(const ::std::string& value);
  inline void set_columnname(const char* value);
  inline void set_columnname(const char* value, size_t size);
  inline ::std::string* mutable_columnname();
  inline ::std::string* release_columnname();
  
  // repeated uint64 entryList = 2;
  inline int entrylist_size() const;
  inline void clear_entrylist();
  static const int kEntryListFieldNumber = 2;
  inline ::google::protobuf::uint64 entrylist(int index) const;
  inline void set_entrylist(int index, ::google::protobuf::uint64 value);
  inline void add_entrylist(::google::protobuf::uint64 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      entrylist() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_entrylist();
  
  // @@protoc_insertion_point(class_scope:MSG_DS_CS_RTABLE_CREATE.SINGLE_COLUMN_RTABLE)
 private:
  inline void set_has_columnname();
  inline void clear_has_columnname();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* columnname_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > entrylist_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  friend void protobuf_AssignDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* default_instance_;
};
// -------------------------------------------------------------------

class MSG_DS_CS_RTABLE_CREATE : public ::google::protobuf::Message {
 public:
  MSG_DS_CS_RTABLE_CREATE();
  virtual ~MSG_DS_CS_RTABLE_CREATE();
  
  MSG_DS_CS_RTABLE_CREATE(const MSG_DS_CS_RTABLE_CREATE& from);
  
  inline MSG_DS_CS_RTABLE_CREATE& operator=(const MSG_DS_CS_RTABLE_CREATE& from) {
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
  static const MSG_DS_CS_RTABLE_CREATE& default_instance();
  
  void Swap(MSG_DS_CS_RTABLE_CREATE* other);
  
  // implements Message ----------------------------------------------
  
  MSG_DS_CS_RTABLE_CREATE* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_DS_CS_RTABLE_CREATE& from);
  void MergeFrom(const MSG_DS_CS_RTABLE_CREATE& from);
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
  
  typedef MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE SINGLE_COLUMN_RTABLE;
  
  // accessors -------------------------------------------------------
  
  // optional uint32 taskID = 1;
  inline bool has_taskid() const;
  inline void clear_taskid();
  static const int kTaskIDFieldNumber = 1;
  inline ::google::protobuf::uint32 taskid() const;
  inline void set_taskid(::google::protobuf::uint32 value);
  
  // optional uint32 dbID = 2;
  inline bool has_dbid() const;
  inline void clear_dbid();
  static const int kDbIDFieldNumber = 2;
  inline ::google::protobuf::uint32 dbid() const;
  inline void set_dbid(::google::protobuf::uint32 value);
  
  // optional string tableName = 3;
  inline bool has_tablename() const;
  inline void clear_tablename();
  static const int kTableNameFieldNumber = 3;
  inline const ::std::string& tablename() const;
  inline void set_tablename(const ::std::string& value);
  inline void set_tablename(const char* value);
  inline void set_tablename(const char* value, size_t size);
  inline ::std::string* mutable_tablename();
  inline ::std::string* release_tablename();
  
  // optional uint32 attributeCount = 4;
  inline bool has_attributecount() const;
  inline void clear_attributecount();
  static const int kAttributeCountFieldNumber = 4;
  inline ::google::protobuf::uint32 attributecount() const;
  inline void set_attributecount(::google::protobuf::uint32 value);
  
  // repeated .MSG_DS_CS_RTABLE_CREATE.SINGLE_COLUMN_RTABLE columnRTables = 5;
  inline int columnrtables_size() const;
  inline void clear_columnrtables();
  static const int kColumnRTablesFieldNumber = 5;
  inline const ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& columnrtables(int index) const;
  inline ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* mutable_columnrtables(int index);
  inline ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* add_columnrtables();
  inline const ::google::protobuf::RepeatedPtrField< ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE >&
      columnrtables() const;
  inline ::google::protobuf::RepeatedPtrField< ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE >*
      mutable_columnrtables();
  
  // @@protoc_insertion_point(class_scope:MSG_DS_CS_RTABLE_CREATE)
 private:
  inline void set_has_taskid();
  inline void clear_has_taskid();
  inline void set_has_dbid();
  inline void clear_has_dbid();
  inline void set_has_tablename();
  inline void clear_has_tablename();
  inline void set_has_attributecount();
  inline void clear_has_attributecount();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::uint32 taskid_;
  ::google::protobuf::uint32 dbid_;
  ::std::string* tablename_;
  ::google::protobuf::RepeatedPtrField< ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE > columnrtables_;
  ::google::protobuf::uint32 attributecount_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  friend void protobuf_AssignDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_DS_CS_RTABLE_CREATE* default_instance_;
};
// -------------------------------------------------------------------

class MSG_CS_DS_RTABLE_CREATE_ACK : public ::google::protobuf::Message {
 public:
  MSG_CS_DS_RTABLE_CREATE_ACK();
  virtual ~MSG_CS_DS_RTABLE_CREATE_ACK();
  
  MSG_CS_DS_RTABLE_CREATE_ACK(const MSG_CS_DS_RTABLE_CREATE_ACK& from);
  
  inline MSG_CS_DS_RTABLE_CREATE_ACK& operator=(const MSG_CS_DS_RTABLE_CREATE_ACK& from) {
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
  static const MSG_CS_DS_RTABLE_CREATE_ACK& default_instance();
  
  void Swap(MSG_CS_DS_RTABLE_CREATE_ACK* other);
  
  // implements Message ----------------------------------------------
  
  MSG_CS_DS_RTABLE_CREATE_ACK* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MSG_CS_DS_RTABLE_CREATE_ACK& from);
  void MergeFrom(const MSG_CS_DS_RTABLE_CREATE_ACK& from);
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
  
  // optional int32 statusCode = 1;
  inline bool has_statuscode() const;
  inline void clear_statuscode();
  static const int kStatusCodeFieldNumber = 1;
  inline ::google::protobuf::int32 statuscode() const;
  inline void set_statuscode(::google::protobuf::int32 value);
  
  // optional uint32 taskID = 2;
  inline bool has_taskid() const;
  inline void clear_taskid();
  static const int kTaskIDFieldNumber = 2;
  inline ::google::protobuf::uint32 taskid() const;
  inline void set_taskid(::google::protobuf::uint32 value);
  
  // @@protoc_insertion_point(class_scope:MSG_CS_DS_RTABLE_CREATE_ACK)
 private:
  inline void set_has_statuscode();
  inline void clear_has_statuscode();
  inline void set_has_taskid();
  inline void clear_has_taskid();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 statuscode_;
  ::google::protobuf::uint32 taskid_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  friend void protobuf_AssignDesc_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  friend void protobuf_ShutdownFile_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto();
  
  void InitAsDefaultInstance();
  static MSG_CS_DS_RTABLE_CREATE_ACK* default_instance_;
};
// ===================================================================


// ===================================================================

// MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE

// optional string columnName = 1;
inline bool MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::has_columnname() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::set_has_columnname() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::clear_has_columnname() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::clear_columnname() {
  if (columnname_ != &::google::protobuf::internal::kEmptyString) {
    columnname_->clear();
  }
  clear_has_columnname();
}
inline const ::std::string& MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::columnname() const {
  return *columnname_;
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::set_columnname(const ::std::string& value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::set_columnname(const char* value) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(value);
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::set_columnname(const char* value, size_t size) {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  columnname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::mutable_columnname() {
  set_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    columnname_ = new ::std::string;
  }
  return columnname_;
}
inline ::std::string* MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::release_columnname() {
  clear_has_columnname();
  if (columnname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = columnname_;
    columnname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated uint64 entryList = 2;
inline int MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::entrylist_size() const {
  return entrylist_.size();
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::clear_entrylist() {
  entrylist_.Clear();
}
inline ::google::protobuf::uint64 MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::entrylist(int index) const {
  return entrylist_.Get(index);
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::set_entrylist(int index, ::google::protobuf::uint64 value) {
  entrylist_.Set(index, value);
}
inline void MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::add_entrylist(::google::protobuf::uint64 value) {
  entrylist_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::entrylist() const {
  return entrylist_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE::mutable_entrylist() {
  return &entrylist_;
}

// -------------------------------------------------------------------

// MSG_DS_CS_RTABLE_CREATE

// optional uint32 taskID = 1;
inline bool MSG_DS_CS_RTABLE_CREATE::has_taskid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_has_taskid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_has_taskid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_taskid() {
  taskid_ = 0u;
  clear_has_taskid();
}
inline ::google::protobuf::uint32 MSG_DS_CS_RTABLE_CREATE::taskid() const {
  return taskid_;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_taskid(::google::protobuf::uint32 value) {
  set_has_taskid();
  taskid_ = value;
}

// optional uint32 dbID = 2;
inline bool MSG_DS_CS_RTABLE_CREATE::has_dbid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_has_dbid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_has_dbid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_dbid() {
  dbid_ = 0u;
  clear_has_dbid();
}
inline ::google::protobuf::uint32 MSG_DS_CS_RTABLE_CREATE::dbid() const {
  return dbid_;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_dbid(::google::protobuf::uint32 value) {
  set_has_dbid();
  dbid_ = value;
}

// optional string tableName = 3;
inline bool MSG_DS_CS_RTABLE_CREATE::has_tablename() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_has_tablename() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_has_tablename() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_tablename() {
  if (tablename_ != &::google::protobuf::internal::kEmptyString) {
    tablename_->clear();
  }
  clear_has_tablename();
}
inline const ::std::string& MSG_DS_CS_RTABLE_CREATE::tablename() const {
  return *tablename_;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_tablename(const ::std::string& value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_DS_CS_RTABLE_CREATE::set_tablename(const char* value) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(value);
}
inline void MSG_DS_CS_RTABLE_CREATE::set_tablename(const char* value, size_t size) {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  tablename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MSG_DS_CS_RTABLE_CREATE::mutable_tablename() {
  set_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    tablename_ = new ::std::string;
  }
  return tablename_;
}
inline ::std::string* MSG_DS_CS_RTABLE_CREATE::release_tablename() {
  clear_has_tablename();
  if (tablename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = tablename_;
    tablename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional uint32 attributeCount = 4;
inline bool MSG_DS_CS_RTABLE_CREATE::has_attributecount() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_has_attributecount() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_has_attributecount() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_attributecount() {
  attributecount_ = 0u;
  clear_has_attributecount();
}
inline ::google::protobuf::uint32 MSG_DS_CS_RTABLE_CREATE::attributecount() const {
  return attributecount_;
}
inline void MSG_DS_CS_RTABLE_CREATE::set_attributecount(::google::protobuf::uint32 value) {
  set_has_attributecount();
  attributecount_ = value;
}

// repeated .MSG_DS_CS_RTABLE_CREATE.SINGLE_COLUMN_RTABLE columnRTables = 5;
inline int MSG_DS_CS_RTABLE_CREATE::columnrtables_size() const {
  return columnrtables_.size();
}
inline void MSG_DS_CS_RTABLE_CREATE::clear_columnrtables() {
  columnrtables_.Clear();
}
inline const ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE& MSG_DS_CS_RTABLE_CREATE::columnrtables(int index) const {
  return columnrtables_.Get(index);
}
inline ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* MSG_DS_CS_RTABLE_CREATE::mutable_columnrtables(int index) {
  return columnrtables_.Mutable(index);
}
inline ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE* MSG_DS_CS_RTABLE_CREATE::add_columnrtables() {
  return columnrtables_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE >&
MSG_DS_CS_RTABLE_CREATE::columnrtables() const {
  return columnrtables_;
}
inline ::google::protobuf::RepeatedPtrField< ::MSG_DS_CS_RTABLE_CREATE_SINGLE_COLUMN_RTABLE >*
MSG_DS_CS_RTABLE_CREATE::mutable_columnrtables() {
  return &columnrtables_;
}

// -------------------------------------------------------------------

// MSG_CS_DS_RTABLE_CREATE_ACK

// optional int32 statusCode = 1;
inline bool MSG_CS_DS_RTABLE_CREATE_ACK::has_statuscode() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::set_has_statuscode() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::clear_has_statuscode() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::clear_statuscode() {
  statuscode_ = 0;
  clear_has_statuscode();
}
inline ::google::protobuf::int32 MSG_CS_DS_RTABLE_CREATE_ACK::statuscode() const {
  return statuscode_;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::set_statuscode(::google::protobuf::int32 value) {
  set_has_statuscode();
  statuscode_ = value;
}

// optional uint32 taskID = 2;
inline bool MSG_CS_DS_RTABLE_CREATE_ACK::has_taskid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::set_has_taskid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::clear_has_taskid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::clear_taskid() {
  taskid_ = 0u;
  clear_has_taskid();
}
inline ::google::protobuf::uint32 MSG_CS_DS_RTABLE_CREATE_ACK::taskid() const {
  return taskid_;
}
inline void MSG_CS_DS_RTABLE_CREATE_ACK::set_taskid(::google::protobuf::uint32 value) {
  set_has_taskid();
  taskid_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MSG_5fDS_5fCS_5fRTABLE_5fCREATE_2eproto__INCLUDED
