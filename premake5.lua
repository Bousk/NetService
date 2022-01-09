require "Libs/Net/NetworkLib/NetworkLib"
require "NetService"
require "Sample"

workspace "NetServiceSample"
	configurations { "Debug", "Release" }
	architecture "x64"
	cppdialect "C++17"
	location("./tmp/builds/projects/" .. _ACTION)
		
CreateNetworkLib("Libs/Net/NetworkLib/", "./tmp/builds/files/" .. _ACTION .. "/%{cfg.buildcfg}")
CreateNetServiceLib("./", "./tmp/builds/files/" .. _ACTION .. "/%{cfg.buildcfg}")
CreateNetServiceSample("./", "./builds/%{cfg.buildcfg}")