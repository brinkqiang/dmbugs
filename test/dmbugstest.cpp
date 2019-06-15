
#include "dmbugs.h"
#include "dmos.h"
#include "dmstrtk.hpp"

typedef struct tagFileInfo {
    std::string strFullPathFile;
    std::string strFullPath;
    std::string strModuleName;
    std::string strIDName;
    ///
    std::string strHFileName;
    std::string strHDataName;
} SPackFileInfo;

std::vector<SPackFileInfo> m_vecFileInfo;

void AddFile(const std::string& strPath,
    const std::string& strFullPathPwd, const std::string& strFullPath) {
    SPackFileInfo stFileInfo;
    stFileInfo.strFullPathFile = strPath;
    stFileInfo.strModuleName = strFullPathPwd;
    stFileInfo.strFullPath = strFullPath;
    stFileInfo.strIDName = strFullPathPwd;

    strtk::replace('|', '_', stFileInfo.strIDName);
    strtk::replace('.', '_', stFileInfo.strIDName);
    strtk::replace('-', '_', stFileInfo.strIDName);
    strtk::replace('{', '_', stFileInfo.strIDName);
    strtk::replace('}', '_', stFileInfo.strIDName);
    strtk::replace(' ', '_', stFileInfo.strIDName);

    std::string strReplace;
    strtk::replace_pattern("12fd..3z.v44", "..", "|", strReplace);

    std::replace(std::begin(stFileInfo.strIDName), std::end(stFileInfo.strIDName), ' ', '_');

    stFileInfo.strIDName = strtk::as_lowercase(stFileInfo.strIDName);

    stFileInfo.strHFileName = stFileInfo.strIDName + "_filename";
    stFileInfo.strHDataName = stFileInfo.strIDName + "_data";

    m_vecFileInfo.push_back(stFileInfo);
}

int main( int argc, char* argv[] ) {

    std::string strFile = "test.cpp";

    AddFile("", "ABC{}EFG", "ABC");

    return 0;
}
