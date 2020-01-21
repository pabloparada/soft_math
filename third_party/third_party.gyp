{
  "targets": [
    {
      "target_name": "kissfft",
      "type": "static_library",
      "include_dirs" : ["kiss_fft130"],
      "direct_dependent_settings": {
        "include_dirs": [ "kiss_fft130" ],
      },
      'sources': [
        "kiss_fft130/kiss_fft.c",
        "kiss_fft130/tools/kiss_fftr.c",
      ]
    }
  ]
}