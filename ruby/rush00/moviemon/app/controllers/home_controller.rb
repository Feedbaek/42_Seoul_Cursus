require "#{Rails.root}/lib/data_management.rb"
require "#{Rails.root}/lib/parsing.rb"
require "json"

class HomeController < ApplicationController
	def poweroff
		$view = "root"
        $game = []
        $selected = nil
        $player = {}
	    redirect_to "/title"
	end
	def title
		if $view != "title"
			one_monarr = [731362, 410132, 610672].shuffle
			two_monarr = [628791, 207448, 170775, 740265, 445131].shuffle
			three_monarr = [557035, 10253, 33555, 727037, 518240].shuffle
			strong_monarr = [337404, 293660, 157336, 27205, 11324, 26466, 419430, 70160, 671, 399566].shuffle
			monarr = []
			one_monarr.each{|idx| monarr.push(idx)}
			two_monarr.each{|idx| monarr.push(idx)}
			three_monarr.each{|idx| monarr.push(idx)}

			$game = []
			monarr.length.times {|i|
				begin
					tmp = ParseMovie.new(monarr.pop())
				rescue StandardError => e
					retry
				else
					$game.push({
					"name" => tmp.name,
					"director" => tmp.director,
					"rating" => tmp.rating.to_i,
					"monhp" => tmp.rating.to_i + 1,
					"mondam" => tmp.rating.to_i,
					"year" => tmp.year,
					"genres" => tmp.genres,
					"poster" => tmp.poster.split("_filter(blur)").join(),
					"abstract" => tmp.abstract
					})
				end
			}
		    $selected = Management.new $game
            puts "====GET_MOVIE_TEST===="
            puts $game[0]['name']
            puts $selected.get_movie $game[0]['name']
            puts "----------------------"
            puts $game[1]['name']
            puts $selected.get_movie $game[1]['name']
            puts "----------------------"
		end
		$player = {
			"hp" => 250,
			"dam" => 3,
			"x_pos" => 0,
			"y_pos" => 0,
			"score" => 0,
            "movieball" => 5,
			"dex" => []
		}
		$view = "title"
	end
	def map
        def movechar dir, val
            $player[dir] += val
            if rand(0...100) < 5
                $player["movieball"] += 1
            end
            if rand(0...100) < 8
			    redirect_to "/battle"
            end
        end

		$view = "map"
		if $game[0] == nil
			redirect_to "/game_end"
		end

		btn = params[:button]
		if btn == "up" and $player["y_pos"] > 0
            unless $player["y_pos"] == 175 and $player["x_pos"] >= 100
                movechar "y_pos", -25
            end
		elsif btn == "down" and $player["y_pos"] < 225
            if $player["x_pos"] >= 100 and $player["y_pos"] == 125
                movechar "y_pos", +50
            else
                movechar "y_pos", +25
            end
		elsif btn == "left" and $player["x_pos"] > 0
            movechar "x_pos", -25
		elsif btn == "right" and $player["x_pos"] < 225
            unless $player["x_pos"] == 75 and $player["y_pos"] == 150
                movechar "x_pos", +25
            end
		else
		end
	end

	def battle
		p = params[:button]
		@returl = '/battle?button=a'

		if p == 'a'
			$game[-1]["monhp"] -= $player["dam"]
			$player["hp"] -= $game[-1]["mondam"]
		end

		if $game[-1]["monhp"] - $player["dam"] > 0 and $player["hp"] - $game[-1]["mondam"] < 0
			@returl = '/battle_result?status=0'
		end
		if $game[-1]["monhp"] - $player["dam"] <= 0
			@returl = '/battle_result?status=1'
		end
		$view = "battle"
	end
	def battle_result
		status = params[:status].to_i
		if status == 0
			@message = "You Die"
			@returl = "/map"
            $game.pop()
		elsif status == 1
			@message = "You caught it!"
			@returl = "/map"
            if $player["movieball"] > 0
                $player["score"] += $game[-1]["rating"]
                $player["movieball"] -= 1
            end
			$player["dex"].push($game.pop())
		else
			@message = "You coward!"
			@returl = "/map"
            $game.pop()
		end
        $player["hp"] = 250 + ($player["dex"].length * 1)
		$player["dam"] = 3 + ($player["dex"].length * 1)
		$view = "battle_result"
	end

	def save_slot
		@return = $view
		@command = params[:command]
		@select = params[:select]
		@choice = params[:choice]
		if @choice != nil
			if @return == "map"
				ret = $selected.save(@choice, $game, $player)
                puts ret
				redirect_to '/title'
			elsif @return == "title"
				ret = $selected.load(@choice)
                if ret == 1
                    $game = $selected.game
                    $player = $selected.player
                    puts $player
                    puts $game
                    redirect_to '/map'
                end
			end
		end
		if @select == nil
			@select = 'A'
		end
		if @command == "next"
			if @select == 'A'
				@select = 'B'
			elsif @select == 'B'
				@select = 'C'
			else
				@select = 'A'
			end
		elsif @command == "prev"
			if @select == 'B'
				@select = 'A'
			elsif @select == 'C'
				@select = 'B'
			else
				@select = 'C'
			end
		end
	end

	def moviedex
		@c = params[:command]
		@p = params[:page]
		if @p == nil
			@p = 0
		end
		@dex = $player["dex"]
		if @dex[0] == nil
			return
		end
		if @c == "next"
			@p = (@p.to_i - 1) % @dex.length
		elsif @c == "prev"
			@p = (@p.to_i + 1) % @dex.length
		end
		@year = @dex[@p.to_i]["year"]
		@genres = @dex[@p.to_i]["genres"]
		@director = @dex[@p.to_i]["director"]
		@rating = @dex[@p.to_i]["rating"]
		@abstract = @dex[@p.to_i]["abstract"]
		@poster = @dex[@p.to_i]["poster"]
	    $view = "moviedex"
	end

    def game_end
        $view = "game_end"
    end
end
