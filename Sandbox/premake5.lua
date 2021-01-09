project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/ClemEngine/vendor/spdlog/include",
		"%{wks.location}/ClemEngine/src",
		"%{wks.location}/ClemEngine/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"ClemEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CE_KEYBOARD_AZERTY"
		}		

	filter "configurations:Debug"
		defines "CE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CE_DIST"
		runtime "Release"
		optimize "on"
