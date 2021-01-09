include "./vendor/premake/premake_customization/solution_items.lua"

workspace "ClemEngine"
	architecture "x86_64"
	startproject "ClemEngine-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/ClemEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/ClemEngine/vendor/GLAD/include"
IncludeDir["ImGui"] = "%{wks.location}/ClemEngine/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/ClemEngine/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/ClemEngine/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/ClemEngine/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/ClemEngine/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/ClemEngine/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "ClemEngine/vendor/GLFW"
	include "ClemEngine/vendor/Glad"
	include "ClemEngine/vendor/imgui"
	include "ClemEngine/vendor/yaml-cpp"
group ""

include "ClemEngine"
include "Sandbox"
include "ClemEngine-Editor"
