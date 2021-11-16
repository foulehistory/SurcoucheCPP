﻿#pragma once
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class Byte : public Object, public IEquatable<byte>
    {
#pragma region f/p
    private:
        byte mValue = 0;
    public:
        static const constexpr byte MinValue = 0;
        static const constexpr byte MaxValue = 255;
#pragma endregion f/p
#pragma region constructor
    public:
        Byte()=default;
        Byte(const byte& _byte);
        Byte(const Byte& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        static Byte Parse(const String& _str);
#pragma endregion custom methods
#pragma region override
    public:
        Boolean Equals(const unsigned char& _object) override;
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
    public:
        Byte& operator=(const Byte& _other);
        operator byte()const { return mValue;}
        Boolean operator==(const Byte& _other) const;
        Boolean operator!=(const Byte& _other) const;
#pragma endregion operator
    };
}
