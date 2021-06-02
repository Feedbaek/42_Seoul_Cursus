#!/usr/bin/env ruby -w

require 'nokogiri'
require 'open-uri'

class ParseMovie
  attr_accessor :name, :director, :rating, :year, :genres, :poster, :abstract, :o_header

  def initialize pnum
    url = "https://www.themoviedb.org/"
    html = Nokogiri::HTML(URI.open("#{url}/movie/#{pnum}"))
    o_header = html.css("#original_header")
    @o_header = o_header

    @rating = o_header.css(".user_score_chart")[0]['data-percent']
    header_list = o_header.css(".header_info > ol > li")
    header_list.each {|ele|
      if ele.css(".character").children[0].to_s.include? "Director"
        @director = ele.css("a").children[0].to_s
      end
    }
    @year = o_header.css(".release").children.to_s.split[0].split('/')[2]
    @genres = ""
    o_header.css(".genres").css("a").each{|e| @genres += e.children.to_s + " "}
    @poster = url + o_header.css(".image_content").css("img")[0]['data-src']
    @abstract = o_header.css(".overview").css("p").children.to_s
    @name = o_header.css("div.title > h2 > a").children.to_s
  end
end
