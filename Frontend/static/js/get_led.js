function get_data(){
    var urlParams = new URLSearchParams(window.location.search);
    id = urlParams.get('id');
    console.log(id)

    const URL = "https://esp32-api-2b745173c4b8.herokuapp.com/iot/"
    console.log(URL)
    var request = new XMLHttpRequest;
    request.open('GET',URL +"/" +email,true);
    request.send();
    request.onload = () => {
        const response = request.responseText;
        const json = JSON.parse(response);
        console.log("response: " + response);
        console.log("json: " + json);
        console.log("status_code: " + request.status);
    }
}