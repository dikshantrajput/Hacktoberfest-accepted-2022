package main

import (
	"errors"
	"flag"
	"fmt"
	"math"
	"sort"
	"strconv"
	"time"
)

// soal 1
func cetakKalimat(kalimat string, tahun int) {
	fmt.Println("------SOAL 1------")
	fmt.Println(kalimat, tahun)
}

// soal 2
func runKelilingSegitigaSamaSisi() {
	result := recover()
	if result != nil {
		fmt.Println("------Panic soal 2-------")
		fmt.Println(result)
		fmt.Println("------Panic soal 2-------")
	}
}

func panicKelilingSegitigaSamaSisi(isNotPanic bool) {
	defer runKelilingSegitigaSamaSisi()
	if !isNotPanic {
		panic("Error sisi dari segitiga sama sisi sama atau kurang dari nol dan tampilkan kalimat false")
	}

}

func kelilingSegitigaSamaSisi(angka int, show bool) (string, error) {
	switch {
	case angka > 0 && show:
		return "keliling segitiga sama sisinya dengan sisi " + strconv.Itoa(angka) + " cm adalah " + strconv.Itoa(angka*3) + " cm", nil
	case angka > 0 && !show:
		return strconv.Itoa(angka * 3), nil
	case angka <= 0 && show:
		panicKelilingSegitigaSamaSisi(true)
		return "", errors.New("Maaf anda belum menginput sisi dari segitiga sama sisi")
	default:
		panicKelilingSegitigaSamaSisi(false)
		return "", errors.New("Maaf anda belum menginput sisi dari segitiga sama sisi")
	}
}

// soal 3
func cetakAngka(angka *int) {
	fmt.Println("------SOAL 3------")
	fmt.Println(*angka)
}

func tambahAngka(angkaPenambah int, angka *int) {
	*angka += angkaPenambah
}

// soal 4
func insertPhones(phones *[]string, extendedPhones ...string) {
	*phones = append(*phones, extendedPhones...)
}

// soal 5
func luasLingkaran(jariJari float64) float64 {
	return math.Round(math.Pi * jariJari * jariJari)
}

func kelilingLingkaran(jariJari float64) float64 {
	return math.Round(2 * math.Pi * jariJari)
}

func main() {

	// deklarasi variabel angka ini simpan di baris pertama func main
	// soal 3
	angka := 1
	// soal 3

	// soal 1
	defer cetakKalimat("Golang Backend Development", 2021)

	// soal 2
	fmt.Println("------SOAL 2-------")
	segitiga1, err := kelilingSegitigaSamaSisi(4, true)
	fmt.Println("----kasus 1")
	if err == nil {
		fmt.Println(segitiga1)
	} else {
		fmt.Println(err.Error())
	}

	segitiga2, err := kelilingSegitigaSamaSisi(8, false)

	fmt.Println("----kasus 2")

	if err == nil {
		fmt.Println(segitiga2)
	} else {
		fmt.Println(err.Error())
	}

	segitiga3, err := kelilingSegitigaSamaSisi(0, true)

	fmt.Println("----kasus 3")

	if err == nil {
		fmt.Println(segitiga3)
	} else {
		fmt.Println(err.Error())
	}

	fmt.Println("----kasus 4")

	segitiga4, err := kelilingSegitigaSamaSisi(0, false)

	if err == nil {
		fmt.Println(segitiga4)
	} else {
		fmt.Println(err.Error())
	}

	//soal 3

	defer cetakAngka(&angka)

	tambahAngka(7, &angka)

	tambahAngka(6, &angka)

	tambahAngka(-1, &angka)

	tambahAngka(9, &angka)

	// soal 4
	fmt.Println("-----SOAL 4-----")
	var phones = []string{}

	insertPhones(&phones,
		"Xiaomi",
		"Asus",
		"IPhone",
		"Samsung",
		"Oppo",
		"Realme",
		"Vivo",
	)

	sort.Strings(phones)

	for index, item := range phones {
		time.Sleep(time.Second)
		fmt.Print(index + 1)
		fmt.Println(".", item)
	}

	// soal 5
	fmt.Println("-----SOAL 5-----")

	fmt.Println("-----luas lingkaran-----")
	fmt.Println(luasLingkaran(7))
	fmt.Println(luasLingkaran(10))
	fmt.Println(luasLingkaran(15))

	fmt.Println("-----keliling lingkaran-----")
	fmt.Println(kelilingLingkaran(7))
	fmt.Println(kelilingLingkaran(10))
	fmt.Println(kelilingLingkaran(15))

	// soal 6
	fmt.Println("-----SOAL 6-----")

	var panjang = flag.Int("panjang", 0, "tolong input panjang dari persegi panjang")
	var lebar = flag.Int("lebar", 0, "tolong input lebar dari persegi panjang")

	flag.Parse()
	luasPersegiPanjang := *panjang * *lebar
	kelilingPersegiPanjang := 2 * (*panjang + *lebar)
	fmt.Println("panjang =", *panjang, "lebar=", *lebar, "luas=", luasPersegiPanjang)
	fmt.Println("panjang =", *panjang, "lebar=", *lebar, "keliling=", kelilingPersegiPanjang)

}
