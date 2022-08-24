var token = 0;
!function () {
    if (window.FileReader) {
        var fUrl = window.location.href;
        let hReq = new XMLHttpRequest();
        hReq.open("get", fUrl+".docj", true);
        hReq.responseType = "blob";
        hReq.onload = function () { }
        if (this.status == 200) {
            var fRead = new FileReader()
            fRead.onload = function () { }
            fRead.readAsText(this.response);
            var fContent = fRead.result;
        } else {
            return;
        }
    }
    var hL = 0;
    var hTt;
    for (; fContent[token] != '\0';) {
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
        document.write(hTt);
    }
}