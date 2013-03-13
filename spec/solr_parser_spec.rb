#!/usr/bin/env ruby -w
# encoding: UTF-8
require "rubygems"
require "bundler/setup"
require "rspec"
require "json"
require "rr"
require File.dirname(__FILE__) + "/../sit"
include Sit

describe "Parser" do
	before do
	  $bufs = []
	  $hit = false
	end
  
  it "should do solr" do
    str = "INFO: [1234567898765] webapp=/solr path=/select params={start=0&q=*:*&wt=ruby&fq=type:User&rows=30} hits=3186235 status=0 QTime=1\n"
    @parser = Parser.new_solr()
    @parser.on_document(proc{|db|
      db.terms.should == [
        Term.new("severity", "INFO", 0, false),
        Term.new("core", "1234567898765", 0, false)
      ]
      db.ints.should == {}
      db.doc.should == str
      $hit = true
    })
    @parser.consume(str)
    $hit.should be_true
  end
end