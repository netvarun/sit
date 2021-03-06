#!/usr/bin/env ruby -w
# encoding: UTF-8
require File.dirname(__FILE__) + "/test_helper"

describe "PString" do
	it "should roundtrip" do
		rstr = "hello world"
		pstr = PString.new(rstr)
		pstr.to_s.should == rstr
	end
	
	it "should be comparable" do
	  ra = "hello world"
		a = PString.new(ra)
		
		rb = "goodbye world"
		b = PString.new(rb)
		
		a.should > b
  end
  
  it "should be appendable" do
    rb = "goodbye world"
		b = PString.new(rb)
    b << "!!!"
    b.to_s.should == rb + "!!!"
  end
end