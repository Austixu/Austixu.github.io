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
    console.log(fContent);
}