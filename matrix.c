#include <stdio.h>
#include <stdlib.h>
#include "include/lua.h"
#include "include/lualib.h"
#include "include/lauxlib.h"
#include "luadebug.h"

int main () {
    const char *fn = "double_matrix.lua";
    lua_State *lua = luaL_newstate();
    luaL_openlibs(lua);
    if ( luaL_dofile(lua, fn) != 0 ) {
        printf("failed execute %s\n", fn);
        exit(1);
    }

    lua_getglobal(lua, "double");

    lua_newtable(lua);

    int arr[][5] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 }
    };

    int i, j;
    for ( i = 0; i < 2; i++ ) {
        lua_newtable(lua);
        for ( j = 0; j < 5; j++ ) {
            lua_pushnumber(lua, arr[i][j]);
            lua_rawseti(lua, 3, j + 1);
        }
        lua_rawseti(lua, 2, i + 1);
    }

    lua_call(lua, 1, 1);

    int value;
    for ( i = 0; i < 2; i++ ) {
        lua_rawgeti(lua, -1, i + 1);
        for ( j = 0; j < 5; j++ ) {
            lua_rawgeti(lua, -1, j + 1);
            if ( j == 0 ) printStack(lua);
            value = lua_tonumber(lua, -1);
            printf("[%d][%d] : %d\n", i, j, value);

            lua_pop(lua, 1);
        }
        lua_pop(lua, 1);
    }

    lua_close(lua);

    return 0;
}
