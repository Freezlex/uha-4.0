package com.freezlex.microservice.model;

public class Product {
    private int id;
    private int price;
    private String name;

    public Product() {

    }

    public Product(String name, int price, int id) {
        this.name = name;
        this.id = id;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String toString() {
        return "Product{" +
                "id=" + id +
                ", name=" + name +
                ", price=" + price + "}";
    }
}
