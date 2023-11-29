function on_off(id) {
    const URI = "https://esp32-api-2b745173c4b8.herokuapp.com/iot/1"

    var request = new XMLHttpRequest;
    request.open('GET',URI)
    request.send()
    request.onload = () => {
        const response = request.responseText;
        const json = JSON.parse(response);
        valor = json[0]["valor"]
        console.log("valor: " + valor);

    }


}
