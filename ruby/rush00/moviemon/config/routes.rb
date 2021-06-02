Rails.application.routes.draw do
	get '/' => 'home#poweroff'
	get "/title" => "home#title"
	get "/save_slot" => "home#save_slot"
	get "/moviedex" => "home#moviedex"
	get "/map" => "home#map"
	get "/battle" => "home#battle"
	get "/battle_result" => "home#battle_result"
	get "/game_end" => "home#game_end"
end
