!function () {
    var token = 0;
    if (window.FileReader) {
        var fPath = window.location.pathname;
        if (this.status == 200) {
            var fRead = new FileReader()
            fRead.onload = function () { }
            fRead.readAsText("/"+fPath);
            var fContent = fRead.result;
        } else {
            return;
        }
    }
    var hL = 0;
    var hTt;
    for (var i = 0;i<100;i++) {
        if (fContent[token] == '#') {  
            ++hL; ++token;
        } else {
            for (; fContent[token] != ';';) {
                hTt += fContent[token];
                token++;
            }
            token++;
            for (; fContent[token] == '\n'; token++);
        }
    }
    document.write(hTt);
}