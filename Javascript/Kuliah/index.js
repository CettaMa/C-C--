var namaMahasiswa = "Sani paisal";
const pi=3.14;
if(true)
{
    let namaMahasiswi = "rayyan mahmud";
    console.log(`${namaMahasiswi} dan ${namaMahasiswa}`)
}

var arrMatakuliah= Array("pemograman mobile", "kalkulus","webdata");

console.log(arrMatakuliah[2]);

var objekMahasiswa= {
    nama:"Cettama",
    kelas:"tk-45-04",
    semester:3,
    arrmataKuliah : ["program mobile", "kalkulus", "webdata"],
}

console.log(objekMahasiswa.arrmataKuliah[1]);

for(var i=0; i<10 ;i++){
    console.log(i);
}

function penjumlahan(a,b) {
    return a+b;
}

var hasilPerkalian= penjumlahan(1,3)

console.log(hasilPerkalian)
