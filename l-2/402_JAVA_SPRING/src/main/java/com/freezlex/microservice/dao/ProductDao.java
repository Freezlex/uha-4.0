package com.freezlex.microservice.dao;

import com.freezlex.microservice.model.Product;

import java.util.List;

public interface ProductDao {
    public List<Product> findAll();

    public Product ProductFindById(int id);

    public Product ProductSave(Product product);

    public void ProductDelete(int id);
}
