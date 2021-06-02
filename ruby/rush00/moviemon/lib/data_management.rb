#!/usr/bin/env ruby -w

require 'json'

class Management
  attr_accessor :game, :player

  def initialize init_game
    @init_game = init_game
    unless File.exist? "./app/save.json"
      file = File.new("./app/save.json", "w+")
      save = {}
      slot = {}
      slot["game"] = []
      slot["player"] = {}
      save["A"] = slot
      save["B"] = slot
      save["C"] = slot
      file.puts save.to_json
      file.close
    end
  end

  def save slot, game, player
    file = File.new("./app/save.json", "r+")
    parse_data = JSON.parse(file.read)
    file.close
    file = File.new("./app/save.json", "w+")
    save = parse_data[slot]
    save["game"] = game
    save["player"] = player
    parse_data[slot] = save
    file.puts parse_data.to_json
    file.close
  end

  def load slot
    file = File.new("./app/save.json", "r+")
    parse_data = JSON.parse(file.read)
    file.close
    @game = parse_data[slot]["game"]
    @player = parse_data[slot]["player"]
    ret = 1
    if @game == [] or @player == {}
      ret = 0
    end
    return ret
  end

  def get_movie name
    @init_game.each {|idx|
      if idx["name"] == name
        return idx
      end
    }
    return {}
  end
end
