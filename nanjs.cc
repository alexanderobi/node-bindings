#include <nan.h>
#include "native.h"

using v8::Function;
using v8::Local;
using v8::Name;
using v8::Value;
using Nan::AsyncQueueWorker;
using Nan::AsyncWorker;
using Nan::Callback;
using Nan::HandleScope;
using Nan::New;
using Nan::Null;
using Nan::To;
using namespace native;

class NanjsWorker : public AsyncWorker {

  private:
    string file;
    string content;

  public:
    NanjsWorker(string file, Callback *callback)
      : AsyncWorker(callback){
        this->file = file;
      }
    ~NanjsWorker() { }

    void Execute (){
      Fileclass fileclass(file);
      content = fileclass.readFromFile(file);
    }

    void HandleOKCallback () {
      HandleScope scope;
      v8::Local<v8::Value> argv[] = {
          Null()
        , New(content).ToLocalChecked()
      };
      callback->Call(2, argv, async_resource);
    }
};

NAN_METHOD(readFromFile) {
  AsyncQueueWorker(new NanjsWorker(
    std::string(*Nan::Utf8String(info[0]->ToString())),
    new Callback(info[1].As<v8::Function>())
  ));
}