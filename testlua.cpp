/**
 * @file	testlua.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-07-06
 */

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int foo(lua_State* L)
{
	int n = lua_tonumber(L, 1);
	lua_pushnumber(L, n+1);
	return 1;
}

int main()
{
	lua_State* l = luaL_newstate();

	luaL_openlibs(l);

	lua_register(l, "foo", foo);

	luaL_dofile(l, "hello.lua");

	lua_close(l);

	return 0;
}
