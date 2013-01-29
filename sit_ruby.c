/**
 * Listing of all of the ruby classes to load.  The class definitions themselves
 * are either in Ruby inlined here (if they're really simple), or in <class>_ruby.c
 */

#include "ruby.h"
#include "pstring_ruby.h"
#include "ring_buffer_ruby.h"
#include "term_ruby.h"
#include "callback_ruby.h"
#include "query_ruby.h"
#include "parser_ruby.h"
#include "engine_ruby.h"
#include "lrw_dict_ruby.h"
#include "plist_ruby.h"

VALUE rbc_pstring;
VALUE rbc_ring_buffer;
VALUE rbc_term;
VALUE rbc_callback;
VALUE rbc_query;
VALUE rbc_parser;
VALUE rbc_engine;
VALUE rbc_lrw_dict;
VALUE rbc_plist_pool;
VALUE rbc_plist;
VALUE rbc_plist_entry;

void 
Init_sit() {
	VALUE m_sit = rb_define_module("Sit");
	
	// PString
	rbc_pstring = rb_define_class_under(m_sit, "PString", rb_cObject);
	rb_define_singleton_method(rbc_pstring, "new", rbc_pstring_new, 1);
	rb_define_method(rbc_pstring, "to_s", rbc_pstring_to_s, 0);
	rb_define_method(rbc_pstring, "<=>", rbc_pstring_comparator, 1);
	rb_include_module(rbc_pstring, rb_mComparable);
	
	// RingBuffer
	rbc_ring_buffer = rb_define_class_under(m_sit, "RingBuffer", rb_cObject);
	rb_define_singleton_method(rbc_ring_buffer, "new", rbc_ring_buffer_new, 1);
	rb_define_method(rbc_ring_buffer, "append", rbc_ring_buffer_append, 1);
	rb_define_method(rbc_ring_buffer, "get", rbc_ring_buffer_get, 2);
	
	// Term
	rbc_term = rb_define_class_under(m_sit, "Term", rb_cObject);
	rb_define_singleton_method(rbc_term, "new", rbc_term_new, 3);
	rb_define_method(rbc_term, "to_s", rbc_term_to_s, 0);
	rb_define_method(rbc_term, "<=>", rbc_term_comparator, 1);
	rb_include_module(rbc_term, rb_mComparable);
	
	// Callback
	rbc_callback = rb_define_class_under(m_sit, "Callback", rb_cObject);
	rb_define_singleton_method(rbc_callback, "new", rbc_callback_new, 2);
	rb_define_method(rbc_callback, "call", rbc_callback_call, 1);
	rb_define_method(rbc_callback, "to_s", rbc_callback_to_s, 0);

	// Query
	rbc_query = rb_define_class_under(m_sit, "Query", rb_cObject);
	rb_define_singleton_method(rbc_query, "new", rbc_query_new, 2);
	rb_define_method(rbc_query, "to_s", rbc_query_to_s, 0);

	// Parser
	rbc_parser = rb_define_class_under(m_sit, "Parser", rb_cObject);
	rb_define_singleton_method(rbc_parser, "new", rbc_parser_new, 0);
	rb_define_method(rbc_parser, "initialize", rbc_parser_initialize, 0);
	rb_define_method(rbc_parser, "engine=", rbc_parser_set_engine, 1);
	rb_define_method(rbc_parser, "engine", rbc_parser_engine, 0);
	rb_define_method(rbc_parser, "consume", rbc_parser_consume, 1);
	rb_define_method(rbc_parser, "term_found", rbc_parser_term_found, 3);
	rb_define_method(rbc_parser, "document_found", rbc_parser_document_found, 2);
	rb_define_method(rbc_parser, "field_found", rbc_parser_field_found, 1);
	
	// Engine
	rbc_engine = rb_define_class_under(m_sit, "Engine", rb_cObject);
	rb_define_singleton_method(rbc_engine, "new", rbc_engine_new, 2);
	rb_define_method(rbc_engine, "parser", rbc_engine_parser, 0);

	// LrwDict
	rbc_lrw_dict = rb_define_class_under(m_sit, "LrwDict", rb_cObject);
	rb_define_singleton_method(rbc_lrw_dict, "new", rbc_lrw_dict_new, 1);
	rb_define_method(rbc_lrw_dict, "[]", rbc_lrw_dict_get, 1);
	rb_define_method(rbc_lrw_dict, "[]=", rbc_lrw_dict_put, 2);
	rb_define_method(rbc_lrw_dict, "capacity", rbc_lrw_dict_capacity, 0);
	rb_define_method(rbc_lrw_dict, "size", rbc_lrw_dict_size, 0);
	rb_define_method(rbc_lrw_dict, "each", rbc_lrw_dict_each, 0);
	rb_include_module(rbc_lrw_dict, rb_mEnumerable);
	
	// PlistPool
	rbc_plist_pool = rb_define_class_under(m_sit, "PlistPool", rb_cObject);
	rb_define_singleton_method(rbc_plist_pool, "new", rbc_plist_pool_new, 1);
	rb_define_method(rbc_plist_pool, "capacity", rbc_plist_pool_capacity, 0);

	// Plist
	rbc_plist = rb_define_class_under(m_sit, "Plist", rb_cObject);
	rb_define_singleton_method(rbc_plist, "new", rbc_plist_new, 1);
	rb_define_method(rbc_plist, "size", rbc_plist_size, 0);
	rb_define_method(rbc_plist, "blocks_count", rbc_plist_blocks_count, 0);
	rb_define_method(rbc_plist, "region", rbc_plist_region, 0);
	rb_define_method(rbc_plist, "append", rbc_plist_append, 1);
	rb_define_method(rbc_plist, "each", rbc_plist_each, 0);
	rb_define_method(rbc_plist, "ptr", rbc_plist_ptr, 0);
	rb_define_method(rbc_plist, "free", rbc_plist_free, 0);
	rb_include_module(rbc_plist, rb_mEnumerable);

	// PlistEntry
	rbc_plist_entry = rb_define_class_under(m_sit, "PlistEntry", rb_cObject);
	rb_define_singleton_method(rbc_plist_entry, "new", rbc_plist_entry_new, 2);
	rb_define_method(rbc_plist_entry, "to_s", rbc_plist_entry_to_s, 0);
	rb_define_method(rbc_plist_entry, "==", rbc_plist_entry_equals, 1);
	
}
