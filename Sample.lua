function CreateNetServiceSample(baseFolder, outputFolder)
	print("NetService : " .. baseFolder)
	project "NetServiceSample"
		kind "WindowedApp"
		language "C++"
		cppdialect "c++17"
		-- architecture "x64"
		targetdir(outputFolder)
		filter {}
		targetname "NetService"
		
		files {
			baseFolder .. "Sample/**"
		}
		includedirs { baseFolder .. "Sample" }
		
		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"
		
		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"
		
		filter {}
		location("./tmp/builds/projects/" .. _ACTION)
		-- filter "system:windows"
			-- systemversion "10.0.15063.0"
		filter {}
		
		defines {}
		includedirs {
			"Libs/Net/NetworkLib/src",
			baseFolder .. "src"
		}
		filter {}
		libdirs { "./tmp/builds/files/" .. _ACTION .. "/%{cfg.buildcfg}" }
		links {
			"Network",
			"NetService"
		}
		debugdir "$(TargetDir)"
end
