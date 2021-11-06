﻿#include "Language.h"
#include "../../../System/PrimaryType/Integer/Integer.h"
#include "../../../System.IO/Exception/IOException/IOException.h"
#include "../../../System.IO/Stream/StreamReader/StreamReader.h"
#include "../../../System.IO/File/File/File.h"
#include "../../../System.IO/Path/Path.h"
#include "../LanguageManager.h"

Language::Language(const System::String& _name, const System::String& _fileName)
{
    mName = _name;
    mFileName = _fileName;
    const System::String& _path = System::IO::Path::Combine(LanguageManager::Instance().GetPathToSave(), _fileName);
    mFile = System::IO::FileStream(_path);
    if (!mFile.Exists())
        mFile = System::IO::File::Create(_path);
}

Language::Language(const Language& _copy)
{
    mFile = std::move(_copy.mFile);
    mFileName = std::move(_copy.mFileName);
    mName = std::move(_copy.mName);
}

System::String Language::GetMessages(const System::String& _key) const
{
    if (!mFile.IsValid())
        throw System::IO::IOException("file doesn't exist !");
    string _str = string::Empty();
    while(mFile.Reader().ReadLine(_str))
        if (_str.Contains(_key))
            return _str.SubString(_str.FirstIndexOf(':')+2, _str.Length());
    
    return "";
}

System::String Language::GetFileName() const
{
    return mFileName;
}

System::String Language::GetName() const
{
    return mName;
}

System::IO::FileStream Language::GetFile() const
{
    return mFile;
}

Language Language::operator=(const Language& _copy)
{
    mFile = std::move(_copy.mFile);
    mFileName = std::move(_copy.mFileName);
    mName = std::move(_copy.mName);
    return *this;
}
