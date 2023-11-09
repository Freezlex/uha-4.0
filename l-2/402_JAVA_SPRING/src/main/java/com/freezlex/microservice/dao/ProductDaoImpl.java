package com.freezlex.microservice.dao;

import com.freezlex.microservice.model.Product;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

@Repository
public class ProductDaoImpl implements ProductDao {

    public static List<Product> products = new ArrayList<>();

    static {
        products.add(new Product("Ordinateur Gameurzzzz", 1500, 1));
        products.add(new Product("Télé Katka", 850, 2));
        products.add(new Product("Canapé Paultroné saufa", 1200, 3));
        products.add(new Product("Stream de Freezlex", 50000, 4));
    }

    @Override
    public List<Product> findAll() {
        return products;
    }

    @Override
    public Product ProductFindById(int id) {
        for (Product product : products) {
            if (product.getId() == id) {
                return product;
            }
        }
        return null;
    }

    public Product ProductSave(Product product) {
        products.add(product);
        return product;
    }

    public void ProductDelete(int id) {
        products.removeIf(product -> product.getId() == id);
    }
}
