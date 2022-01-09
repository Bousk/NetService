function CreateNetServiceLib(baseLibFolder, outputFolder)
	print("NetService : " .. baseLibFolder)
	project "NetService"
		kind "StaticLib"
		language "C++"
		cppdialect "c++17"
		-- architecture "x64"
		targetdir(outputFolder)
		filter "toolset:codeblocks"
			targetprefix "lib"
		filter {}
		targetname "NetService"
		
		files {
			baseLibFolder .. "src/**.*"
		}
		includedirs {
			"Libs/Net/NetworkLib/src",
			baseLibFolder .. "src"
		}
		
		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"
		
		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"
		filter {}
end
