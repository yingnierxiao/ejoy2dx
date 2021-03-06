
#include "lualibs.h"
#include <lauxlib.h>

static void
_register(lua_State *L, lua_CFunction func, const char * libname) {
  luaL_requiref(L, libname, func, 0);
  lua_pop(L, 1);
}

int luaopen_image(lua_State *L);
int luaopen_serialize(lua_State *L);
int luaopen_osutil(lua_State *L);
int luaopen_monitor(lua_State *L);
int luaopen_easing(lua_State *L);

void
init_lua_libs(lua_State* L) {
	_register(L, luaopen_image, "ejoy2dx.image.c");
	_register(L, luaopen_osutil, "ejoy2dx.osutil.c");
	_register(L, luaopen_serialize, "ejoy2dx.serialize.c");
	_register(L, luaopen_easing, "ejoy2dx.easing.c");
  
#ifdef DEBUG
  _register(L, luaopen_monitor, "ejoy2dx.lmonitor.c");
#endif

}
