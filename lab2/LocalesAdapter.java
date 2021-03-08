//.b=30
package com.example.proyectofinal;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class LocalesAdapter extends RecyclerView.Adapter<LocalesAdapter.LocalesViewHolder> {
    //.i
    public class LocalesViewHolder extends RecyclerView.ViewHolder{

        public TextView texto1, texto2;
        //.i
        public LocalesViewHolder(@NonNull View itemView){
            super(itemView);

            texto1 = itemView.findViewById(R.id.nameTV); //.m
            texto2 = itemView.findViewById(R.id.tipoTV); //.m
        }
    }

    private ArrayList<LocalesDP> locales;
    private View.OnClickListener listener;
    //.d=5

	//.i
    public LocalesAdapter(ArrayList<LocalesDP> perritos, View.OnClickListener listener){
        this.locales = perritos;
        this.listener = listener;
    }

	//.i
    @NonNull
    @Override
    public LocalesViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v =(View) LayoutInflater.from(parent.getContext()).inflate(R.layout.row, parent,false);
        v.setOnClickListener(listener);

        LocalesViewHolder avh = new LocalesViewHolder(v);
        return avh;
    }
	//.i
    @Override
    public void onBindViewHolder(@NonNull LocalesViewHolder holder, int position) {
        LocalesDP str = locales.get(position);
        holder.texto1.setText(str.getNombre());
        holder.texto2.setText(str.getTipo());
    }
	//.i
    @Override
    public int getItemCount() {
        return locales.size();
    }
}
