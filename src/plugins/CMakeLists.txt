# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial

if(ANDROID)
    add_subdirectory(android)
endif()
if(NOT ANDROID AND (IOS OR MACOS))
    add_subdirectory(darwin)
endif()
if(WINRT)
    add_subdirectory(winrt)
endif()
if(TARGET Qt::WebEngineCore)
    add_subdirectory(webengine)
endif()
