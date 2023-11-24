import fastapi
import sqlite3
from fastapi.middleware.cors import CORSMiddleware

conn = sqlite3.connect("iot.db")

app = fastapi.FastAPI()

origins = [
    "*"
]
app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/dispositivo")
async def obtener_LED():
    c = conn.cursor()
    # c.execute('SELECT valor FROM iot;')
    c.execute('SELECT * FROM iot;')
    response = []
    for row in c:
        dispositivo = {"id":row[0],"dispositivo":row[1], "valor":row[2]}
        # dispositivo = {"valor":row[0]}
        response.append(dispositivo)
    return response

@app.put("/dispositivo/{id}")
async def actualizar_LED(id: int, valor: int):
    c = conn.cursor()
    c.execute('UPDATE iot SET valor = ? WHERE id = ?;', (valor,id))
    conn.commit()
    return {"mensaje":"Dispositivo actualizado"}
