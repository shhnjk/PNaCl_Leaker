# PNaCl_Leaker
Simple PoC to leak contents from embedded origin using Chrome's PNaCl plugin

Change `target_url` in `url_loader.cc` to your desired exfiltration target.
Change `target_url` in `url_loader_handler.cc` to your leak destination. Note that this destination needs to allow CORS access from embedded origin, and leak destination's response body needs to be `test`.

This is modified version of [url_loader](https://cs.chromium.org/chromium/src/native_client_sdk/src/examples/api/url_loader/) example. Read [Native Client tutorial](https://developer.chrome.com/native-client/devguide/tutorial/tutorial-part1) for how to complile Native Client module.
