#include <nan.h>
#include "nanjs.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_MODULE_INIT(InitAll){
  Set(target, New<String>("readFromFile").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(readFromFile)).ToLocalChecked());
}

NODE_MODULE(nanjs, InitAll)