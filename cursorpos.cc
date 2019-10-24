#include <node.h>
#include <windows.h>

void GetCursorCoordinates(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();

	POINT p;
	if (GetCursorPos(&p))
	{
		auto obj = v8::Object::New(isolate);

		auto x = v8::Number::New(isolate, p.x);
		auto y = v8::Number::New(isolate, p.y);

		obj->Set(v8::String::NewFromUtf8(isolate, "x"), x);
		obj->Set(v8::String::NewFromUtf8(isolate, "y"), y);

    	args.GetReturnValue().Set(obj);
	}
}

void Initialize(v8::Local<v8::Object> exports) {
	NODE_SET_METHOD(exports, "get", GetCursorCoordinates);
}

NODE_MODULE(module_name, Initialize)