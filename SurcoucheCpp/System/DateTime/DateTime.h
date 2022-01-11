﻿#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include <Windows.h>

namespace System
{
    
class DateTime : public Object
{
    DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
    int mDay = 0;
    int mMonth = 0;
    int mYears = 0;
    int mHour = 0;
    int mMinute = 0;
    int mSecond = 0;
public:
    static const DateTime Now;
#pragma endregion f/p
#pragma region constructor
public:
    DateTime() = default;
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour, const Integer& _minute, const Integer& _seconds);
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour, const Integer& _minute);
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour);
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years);
    DateTime(const DateTime& _copy);
#pragma endregion constructor
#pragma region custom methods
private:
    static DateTime Now_Interval();
public:
    static DateTime Convert(SYSTEMTIME _systemTime);
    static DateTime Convert(time_t _systemTime);
    String ToStringFormat(const String& _format =  "y-m-d h:m:s") const;
    Boolean Equals(const DateTime& _other);
    static DateTime FileTimeToDateTime(const FILETIME& _fileTime); 
#pragma endregion custom methods
#pragma region override
public:
    String ToString() const override;
    Boolean Equals(const object* _obj) override;
    Boolean Equals(const object& _obj) override;
    size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
    DateTime& operator=(const DateTime& _other)
    {
        mDay = std::move(_other.mDay);
        mMonth = std::move(_other.mMonth);
        mYears = std::move(_other.mYears);
        mHour = std::move(_other.mHour);
        mMinute = std::move(_other.mMinute);
        mSecond = std::move(_other.mSecond);
        return *this;
    }
#pragma endregion operator
};
}
