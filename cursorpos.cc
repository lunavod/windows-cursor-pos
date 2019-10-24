#include <windows.h>
#include <napi.h>

Napi::Object WinGetCursorPos(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object obj = Napi::Object::New(env);
	POINT p;
	if (GetCursorPos(&p))
	{
		auto x = Napi::Number::New(env, p.x);
		auto y = Napi::Number::New(env, p.y);

		obj.Set(Napi::String::New(env, "x"), x);
		obj.Set(Napi::String::New(env, "y"), y);
	}

  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	return Napi::Function::New(env, WinGetCursorPos, "getCursorPos");
}

NODE_API_MODULE(addon, Init)