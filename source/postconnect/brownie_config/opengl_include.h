#pragma once

/**
 * Copyright (c) 2016-2017 blueback
 * Released under the MIT License
 * https://github.com/bluebackblue/brownie/blob/master/LICENSE.txt
 * http://bbbproject.sakura.ne.jp/wordpress/mitlicense
 * @brief glew glfw
*/


/** GLEW_STATIC
*/
#define GLEW_STATIC


/** include
*/
#pragma warning(push)
#pragma warning(disable:4710 4820)
#include <glew/glew-2.0.0/include/GL/glew.h>
#include <glfw/glfw-3.2.1/include/GLFW/glfw3.h>
#include <glfw/glfw-3.2.1/include/GLFW/glfw3native.h>
#pragma warning(pop)

