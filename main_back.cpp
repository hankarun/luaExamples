//#define SOL_ALL_SAFETIES_ON 1
//#include <sol/sol.hpp>

#include <iostream>
#include <unordered_map>
#include <vector>

#include "SDL.h"

//struct ComponentMessage
//{
//	int getIntdata(int word)
//	{
//		return 42;
//	}
//
//	template <typename L>
//	static void registerLua(L& lua)
//	{
//		lua.new_usertype<ComponentMessage>("ComponentMessage",
//			"new", sol::no_constructor,
//			"getIntData", &ComponentMessage::getIntdata);
//	}
//};
//
//void testLua()
//{
//	sol::state lua;
//	lua.open_libraries(sol::lib::base, sol::lib::package);
//
//	ComponentMessage::registerLua(lua);
//
//	lua.set_function("Log", [](const std::string& message){
//		std::cout << message << std::endl;
//	});
//	
//
//	sol::load_result script1 = lua.load_file("../../test.lua");
//
//	script1();
//
//	std::unordered_map<std::string,std::vector<sol::function>> functions;
//
//	sol::table conf_table = lua["properties"];
//	for (const auto& key_value_pair : conf_table ) {
//		sol::object key = key_value_pair.first;
//		sol::object value = key_value_pair.second;
//
//		if (key.is<std::string>())
//		{
//			std::cout << "Key: " << key.as<std::string>() <<  " ";
//			sol::type type = value.get_type();
//			switch (type)
//			{
//			case sol::type::string:
//				std::cout << "Value: " << value.as<std::string>();
//				break;
//			case sol::type::number:
//				std::cout << "Value: " << value.as<float>();
//				break;			
//			case sol::type::function:
//				{
//					functions[key.as<std::string>()].push_back(value.as<sol::function>());
//				}break;
//			default:
//				std::cout << "Value: unknown.";
//				break;
//			}
//			std::cout << std::endl;
//		}
//	}
//
//	ComponentMessage msg;
//	for(auto& f : functions)
//	{
//		for(auto& s : f.second)
//			s(msg);
//	}
//
//	std::cout << std::endl;
//}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(
		"SDL2Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_RESIZABLE
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_GL_SetSwapInterval(1);

	printf("Platform %s\n", SDL_GetPlatform());
	printf("CPU cores: %d\n", SDL_GetCPUCount());
	printf("RAM: %.2f GB\n", SDL_GetSystemRAM() / 1024.0f);

	bool loop = true;
    while (loop)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
			switch (event.type)
			{
			case SDL_QUIT:
				loop = false;
				break;
			case SDL_WINDOWEVENT:
			{
				switch (event.window.event)
                {
                	case SDL_WINDOWEVENT_RESIZED:
					break;
				}
			}break;
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    loop = false;
                    break;
                }
			}break;
			default:
				break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}