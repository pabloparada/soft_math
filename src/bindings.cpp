#include <napi.h>
#include "../third_party/kiss_fft130/tools/kiss_fftr.h"

using namespace Napi;
using namespace std;

Value B_FFT(const CallbackInfo& info) {
    Napi::Env env = info.Env();

    Array in = info[0].As<Array>();
    int32_t in_l = in.Length();

    kiss_fftr_cfg cfg = kiss_fftr_alloc(in_l, 0, 0, 0);

    kiss_fft_scalar *ins = new kiss_fft_scalar[in_l];

    for (int32_t i = 0; i < in_l; i++) {
        float_t v = in.Get(i).As<Number>().FloatValue();
        ins[i] = v;
    }

    kiss_fft_cpx *outc = new kiss_fft_cpx[in_l + 2];

    kiss_fftr(cfg, ins, outc);

    Array out = Array::New(env, in_l);

    for (int32_t i = 0; i < in_l; i++) {
        out.Set(i, Number::New(env, outc[i].r));
    }

    kiss_fft_free(cfg);
    delete [] ins;
    delete [] outc;

    return out;
}

Object Init(Env env, Object exports) {
    exports.Set(String::New(env, "fft"), Function::New(env, B_FFT));
    return exports;
}

NODE_API_MODULE(fft, Init)