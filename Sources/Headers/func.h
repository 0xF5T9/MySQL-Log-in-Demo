#pragma once
#include "animation.h"
#include "global.h"
#include "authenticate.h"
#include "cmysql.h"
#include "menu.h"

/*	Define create object functions */
animation* CreateObjectAnimation() {
	animation* CreateObject = new animation();
	return CreateObject;
}

global* CreateObjectGlobal() {
	global* CreateObject = new global();
	return CreateObject;
}

authenticate* CreateObjectAuthenticate(global* _Global, cmysql* _CMySQL) {
	authenticate* CreateObject = new authenticate(_Global, _CMySQL);
	return CreateObject;
}

cmysql* CreateObjectCMySQL(global* _Global, animation* _Animation) {
	cmysql* CreateObject = new cmysql(_Global, _Animation);
	return CreateObject;
}

menu* CreateObjectMenu(global* _Global, animation* _Animation) {
	menu* CreateObject = new menu(_Global, _Animation);
	return CreateObject;
}

/*	Define free object memory functions	*/
void FreeMemory(animation* _Ptr) {
	delete _Ptr;
}

void FreeMemory(global* _Ptr) {
	delete _Ptr;
}

void FreeMemory(authenticate* _Ptr) {
	delete _Ptr;
}

void FreeMemory(cmysql* _Ptr) {
	delete _Ptr;
}

void FreeMemory(menu* _Ptr) {
	delete _Ptr;
}