#include <napi.h>
#include "greetings.h"

Napi::String B_Hello(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  std::string name = info[0].ToString();

  return Napi::String::New(env, Hello(name));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, B_Hello));
  return exports;
}

NODE_API_MODULE(hello, Init)