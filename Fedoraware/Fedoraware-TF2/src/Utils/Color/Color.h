#pragma once

#include <string>
#include <sstream>

#include "../Math/Math.h"

#define DEVELOPER_BUILD

using byte = unsigned char;

struct Color_t
{
	byte r = 0, g = 0, b = 0, a = 0;

	bool operator==(Color_t c) const
	{
		return (this->r == c.r && this->g == c.g && this->b == c.b && this->a == c.a);
	}

	bool operator!=(Color_t c) const
	{
		return !(this->r == c.r && this->g == c.g && this->b == c.b && this->a == c.a);
	}

	[[nodiscard]] std::string to_hex() const
	{
		std::stringstream ss;
		ss << "\x7";
		ss << std::hex << (static_cast<int>(r) << 16 | static_cast<int>(g) << 8 | static_cast<int>(b));
		return ss.str();
	}

	[[nodiscard]] std::string to_hex_alpha() const
	{
		std::stringstream ss;
		ss << "\x8";
		ss << std::hex << (static_cast<int>(r) << 16 | static_cast<int>(g) << 8 | static_cast<int>(b));
		ss << std::hex << static_cast<int>(a);
		return ss.str();
	}

	[[nodiscard]] Color_t lerp(Color_t to, float t) const
	{
		//a + (b - a) * t
		return {
			static_cast<byte>(r + (to.r - r) * t),
			static_cast<byte>(g + (to.g - g) * t),
			static_cast<byte>(b + (to.b - b) * t),
			static_cast<byte>(a + (to.a - a) * t),
		};
	}
};

struct Gradient_t
{
	Color_t StartColor = { 0, 0, 0, 255 };
	Color_t EndColor = { 0, 0, 0, 255 };
};

// TODO: Move this shit to a file that isn't this
struct Chams_t
{
	bool	ShowObstructed = false;
	int		DrawMaterial = 0;	// 1/shaded, 2/shiny, 3/flat, 4/wfshaded, 5/wfshiny, 6/wfflat, 7/fresnel, 8/brick 9/custom
	int		OverlayType = 0;
	bool	ChamsActive = true;	// start all chams as active because I don't trust this cheat.
	bool	Rainbow = false;
	bool	OverlayPulse = false;
	bool	OverlayRainbow = false;
	float	OverlayIntensity = 1;
	Color_t FresnelBase = { 0,0,0,255 };
	Color_t Color = { 255, 255, 255, 255 };
	Color_t BluColor = { 255, 255, 255, 255 }; //fuck the british
	Color_t RedColor = { 255, 255, 255, 255 };
	Color_t OverlayColor = { 255, 255, 255, 255 };
	std::string CustomMaterial = "None";
};

struct DragBox_t
{
	int x = 100;
	int y = 100;
	int w = 80;
	int h = 30;
	int c = 140;
	bool update = true;
};

namespace Color
{
	inline float TOFLOAT(byte x)
	{
		return (static_cast<float>(x) / 255.0f);
	}

	inline Vec3 TOVEC3(const Color_t& x)
	{
		return Vec3(TOFLOAT(x.r), TOFLOAT(x.g), TOFLOAT(x.b));
	}

	inline unsigned long TODWORD(const Color_t& x)
	{
		return (static_cast<unsigned long>(((x.r & 0xFF) << 24) | ((x.g & 0xFF) << 16) | ((x.b & 0xFF) << 8) | (x.a & 0xFF)));
	}
}