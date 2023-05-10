//soal sum
sum = (...args) => {
    let x= 0;
    for (let arg of args) x= x + arg;
    return x;
}

hasil=sum(1,2,3,4,5,6,7);
console.log(hasil);

//soal luas lingkaran
luas = (r) => {
    const p=3.14;
    return p*r*r;
}
llingkarang=luas(7);
console.log(llingkarang);

//soal panjang keliling
keliling = (s) =>  s*4;
kpersegi=keliling(5);
console.log(kpersegi);

//mencari nilai terkecil
kecil = (...args) => Math.min(...args)
arrkecil=kecil(11,23,44,13,56,77,45,9);
console.log(arrkecil);

//menghapus genap dari array
genap = (...args) => {
    let output=[];
    for (let arg of args) {
        if (arg%2 !=0){
            output.push(arg);
        }
    }
    return output;
}

Genap=genap(1,3,4,5,6,2,7,90,78);
console.log(Genap);