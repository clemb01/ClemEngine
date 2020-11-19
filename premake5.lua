workspace "ClemEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	startproject "Minecraft"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ClemEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "ClemEngine/vendor/GLAD/include"
IncludeDir["ImGui"] = "ClemEngine/vendor/imgui"

include "ClemEngine/vendor/GLFW"
include "ClemEngine/vendor/Glad"
include "ClemEngine/vendor/imgui"

project "ClemEngine"
	location "ClemEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cepch.h"
	pchsource "ClemEngine/src/cepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CE_PLATFORM_WINDOWS",
			"CE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Minecraft")
		}

	filter "configurations:Debug"
		defines "CE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		runtime "Release"
		optimize "On"

project "Minecraft"
	location "Minecraft"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ClemEngine/vendor/spdlog/include",
		"ClemEngine/src"
	}

	links
	{
		"ClemEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CE_PLATFORM_WINDOWS"
		}		

	filter "configurations:Debug"
		defines "CE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CE_DIST"
		runtime "Release"
		optimize "On"