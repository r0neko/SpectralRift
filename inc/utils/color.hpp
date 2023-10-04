#pragma once

#include <cstdint>
#include <vector>

namespace engine::utils {
#pragma pack(push, 1)
	/// <summary>
	/// Stores a quad-dimensional packed point(RGBA color) of the specified type.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <typename T>
	struct RGBAColor {
		RGBAColor()
			: r(0), g(0), b(0), a(0) {
		}

		explicit RGBAColor(const RGBAColor<T>& rhs)
			: r(rhs.r), g(rhs.g), b(rhs.b), a(rhs.a) {
		}

		explicit RGBAColor(T r, T g, T b, T a = 255)
			: r(r), g(g), b(b), a(a) {
		}

		T r;
		T g;
		T b;
		T a;

		RGBAColor abs() const {
			return { ::abs(r), ::abs(g), ::abs(b), ::abs(a) };
		}

		template <typename T>
		RGBAColor& operator+=(const RGBAColor<T>& r) {
			r += r.r;
			g += r.g;
			b += r.b;
			a += r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator+=(const T& r) {
			r += r;
			g += r;
			b += r;
			a += r;

			return *this;
		}

		template <typename T>
		RGBAColor& operator-=(const RGBAColor<T>& r) {
			r -= r.r;
			g -= r.g;
			b -= r.b;
			a -= r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator-=(const T& r) {
			r -= r;
			g -= r;
			b -= r;
			a -= r;

			return *this;
		}

		template <typename T>
		RGBAColor& operator/=(const RGBAColor<T>& r) {
			r /= r.r;
			g /= r.g;
			b /= r.b;
			a /= r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator/=(const T& r) {
			r /= r;
			g /= r;
			b /= r;
			a /= r;

			return *this;
		}

		template <typename T>
		RGBAColor& operator*=(const RGBAColor<T>& r) {
			r *= r.r;
			g *= r.g;
			b *= r.b;
			a *= r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator*=(const T& r) {
			r *= r;
			g *= r;
			b *= r;
			a *= r;

			return *this;
		}

		template <typename T>
		RGBAColor operator+(const RGBAColor<T>& r) {
			r += r.r;
			g += r.g;
			b += r.b;
			a += r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator+(const T& r) {
			r += r;
			g += r;
			b += r;
			a += r;

			return *this;
		}

		template <typename T>
		RGBAColor operator-(const RGBAColor<T>& r) {
			r -= r.r;
			g -= r.g;
			b -= r.b;
			a -= r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator-(const T& r) {
			r -= r;
			g -= r;
			b -= r;
			a -= r;

			return *this;
		}

		template <typename T>
		RGBAColor operator/(const RGBAColor<T>& r) {
			r /= r.r;
			g /= r.g;
			b /= r.b;
			a /= r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator/(const T& r) {
			r /= r;
			g /= r;
			b /= r;
			a /= r;

			return *this;
		}

		template <typename T>
		RGBAColor<T> operator*(const RGBAColor<T>& r) {
			r *= r.r;
			g *= r.g;
			b *= r.b;
			a *= r.a;

			return *this;
		}

		template <typename T>
		RGBAColor& operator*(const T& r) {
			r *= r;
			g *= r;
			b *= r;
			a *= r;

			return *this;
		}
	};
#pragma pack(pop)

	using Color = RGBAColor<uint8_t>;
	using ColorArray = std::vector<Color>;

	namespace colors {
		static Color black(0, 0, 0);
		static Color white(255, 255, 255);

		static Color red(255, 0, 0);
		static Color green(0, 255, 0);
		static Color blue(0, 0, 255);

		static Color yellow(255, 255, 0);
	} // namespace colors
}