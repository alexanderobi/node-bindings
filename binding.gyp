{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "addon.cc",
        "nanjs.cc",
        "native.cc"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}